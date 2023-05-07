/*********************************************************************************
  *Copyright(C), XiaoHG
  *FileName:  auto_ptr_q
  *Author:  xiaohaige
  *Version:  1.0
  *Date:  2023/5/7
  *Description: open
**********************************************************************************/

#ifndef AUTO_PTR_Q_H
#define AUTO_PTR_Q_H
#include <mutex>

//RAII:即Resource Acquisition Is Initialization，资源获取即初始化，一种利用对象的生命周期来控制资源的技术。注意，这个思想是后面实现智能指针的原理。
//  - 不需要显式释放资源
//  - 对象所需要的资源在他的生命周期内中保持有效

//智能指针的原理
//  - 利用RAII特性: 让对象的生命周期去控制我们资源的生命周期
//  - 面向对象思想，智能指针用类实现需要重载运算符让智能指针有像指针一样的行为

//shared_ptr缺陷：当出现循环引用的时候，由于类对象的析构必须从类的成员开始，就会出现循环的情况。
//weak_ptr就可以解决shared_ptr的循环引用的问题。
//weak_ptr的好处:
//  - 打破递归的依赖关系
//  - 使用一个共享的资源但是不要所有权，不添加引用计数
//  - 避免悬空指针。

namespace xiaohaige{

    //C++98
    template <class T>//智能指针要管理不同类型的指针，实现为类模板
    class auto_ptr//基于管理权转移的思想
    {
        typedef auto_ptr<T> self;
    public:
        auto_ptr(T* ptr)
            :_ptr(ptr)
        {}

        auto_ptr(self& s)
            :_ptr(s._ptr)//转移指针
        {
            s._ptr = nullptr;
        }

        self& operator=(self& s)
        {
            if (_ptr)delete _ptr;//直接释放原指针
            _ptr = s._ptr;//转移指针
            s._ptr = nullptr;
            return *this;
        }

        ~auto_ptr()
        {
            if (_ptr)
                delete _ptr;
        }

        T* operator->() { return _ptr; }
        T operator*() { return *_ptr; }
    private:
        T* _ptr;
    };

    //C++11
    template <class T>//智能指针要管理不同类型的指针，实现为类模板
    class unique_ptr//基于禁止拷贝的思想
    {
        typedef unique_ptr<T> self;
    public:
        unique_ptr(T* ptr = nullptr)
            :_ptr(ptr)
        {}

        unique_ptr(const self& s) = delete;
        self& operator=(const self& s) = delete;

        ~unique_ptr()
        {
            if (_ptr)
                delete _ptr;
        }

        T* operator->() { return _ptr; }
        T operator*() { return *_ptr; }
    private:
        T* _ptr;
    };

    //引用计数存储在堆空间，改变引用计数的函数，有线程安全问题，为了保持线程安全，底层要有互斥锁。
    //注意：智能指针内部实现了加锁，故是线程安全的，但是指针指向的资源不是线程安全的，需要访问的人处理。
    using std::mutex;
    template <class T>//智能指针要管理不同类型的指针，实现为类模板
    class shared_ptr//利用引用计数实现允许拷贝的智能指针
    {
        typedef shared_ptr<T> self;
    public:
        shared_ptr(T* ptr = nullptr)
            :_ptr(ptr)
            ,_pcount(new int(1))
            ,_pmutex(new mutex)
        {}

        shared_ptr(const self& s)
            :_ptr(s._ptr)
            ,_pcount(s._pcount)
            ,_pmutex(s._pmutex)
        {
            (*_pmutex).lock();
            ++(*_pcount);
            (*_pmutex).unlock();
        }

        void Release()
        {
            (*_pmutex).lock();
            bool flag = false;//判断是否需要释放锁,因为这里不能在临界区释放锁
            if (--(*_pcount) == 0 && _ptr && _pcount)//当前指针计数--，s的指针计数++
            {
                delete _ptr;
                delete _pcount;
                flag = true;
            }
            (*_pmutex).unlock();

            if (flag)
                delete _pmutex;
        }

        self& operator=(const self& s)
        {
            if (_ptr != s._ptr)
            {
                Release();
                _ptr = s._ptr;
                _pcount = s._pcount;
                _pmutex = s._pmutex;
                (*_pmutex).lock();
                ++(*_pcount);
                (*_pmutex).unlock();
            }
            return *this;
        }

        ~shared_ptr()
        {
            Release();
        }

        T* operator->() { return _ptr; }
        T operator*() { return *_ptr; }
        int use_count() { return *_pcount; }//返回引用计数
        T* get() const { return _ptr; }//返回指针
    private:
        T* _ptr;
        int* _pcount;//引用计数，当不同对象指针相同时，
        //其计数的地址需要一样,计数大小才能同步,故存储在堆空间
        mutex* _pmutex;//保证线程安全
    };

    template <class T>//智能指针要管理不同类型的指针，实现为类模板
    class weak_ptr//直接拷贝shared_ptr 的指针，不增加引用计数->不参与资源的管理
    {
    public:
        weak_ptr(T* ptr = nullptr)
            :_ptr(ptr)
        {}

        weak_ptr(const shared_ptr<T>& s)
            :_ptr(s.get())
        {}

        weak_ptr<T>& operator=(const shared_ptr<T>& s)
        {
            _ptr = s.get();
            return *this;
        }

        ~weak_ptr()
        {}

        T* operator->() { return _ptr; }
        T operator*() { return *_ptr; }
    private:
        T* _ptr;
    };

};

#endif // AUTO_PTR_Q_H

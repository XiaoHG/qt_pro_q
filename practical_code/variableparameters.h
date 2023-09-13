
#ifndef VARIABLEPARAMETERS_H
#define VARIABLEPARAMETERS_H

#include<tuple>
#include <iostream>
#include <vector>
#include <list>

template<int mycount, int mymaxcount, typename... T>
class myclass
{
public:
    static void mysfunc(const std::tuple<T...>&t)
    {
        std::cout << "value = " << std::get<mycount>(t) << std::endl;
        myclass<mycount + 1, mymaxcount, T...>::mysfunc(t);
    }
};

template<int mymaxcount, typename... T>
class myclass<mymaxcount, mymaxcount, T...>
{
public:
    static void mysfunc(const std::tuple<T...>&t)
    {

    }
};

template <typename... T>
void myfunc(const std::tuple<T...>&t)
{
    myclass<0, sizeof...(T), T...>::mysfunc(t);
}

template <typename T,
         template <typename W> class container
         >
class myClassName
{
public:
    myClassName() {}

private:
    T t;
    container<T> myCon;
};

template<typename T>
using myVec = std::vector<T, std::allocator<T>>;

template<typename T>
using myList = std::list<T, std::allocator<T>>;

class VariableParameters
{
public:
    VariableParameters();
};

#endif // VARIABLEPARAMETERS_H

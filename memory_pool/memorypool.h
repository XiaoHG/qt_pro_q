
#ifndef MEMORYPOOL_H
#define MEMORYPOOL_H


#include <QObject>


class MemoryPool : public QObject
{
    Q_OBJECT
public:
    explicit MemoryPool(QObject *parent = nullptr);

    static void *operator new(size_t size);
    static void operator delete(void *phead);
    static int m_iCount; //分配计数统计，每new一次，就统计一次
    static int m_iMallocCount; //每malloc一次，统计一次

private:
    MemoryPool *next;
    static MemoryPool *m_FreePos; //总是指向一块可以分配出去的内存的首地址
    static int m_sTrunkCount;   //一次分配多少倍的该类内存

signals:

};

#endif // MEMORYPOOL_H

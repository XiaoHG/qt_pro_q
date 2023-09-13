
#include "memorypool.h"

int MemoryPool::m_iCount = 0;
int MemoryPool::m_iMallocCount = 0;
MemoryPool *MemoryPool::m_FreePos = nullptr;
int MemoryPool::m_sTrunkCount = 5; //一次分配5倍的该类内存作为内存池子的大小

MemoryPool::MemoryPool(QObject *parent)
    : QObject{parent}
{

}

void *MemoryPool::operator new(size_t size)
{
    MemoryPool *tmpLink;
    if(m_FreePos == nullptr){

        //为空，需要申请内存，要申请一大块内存
        size_t realSize = m_sTrunkCount * size;
        m_FreePos = reinterpret_cast<MemoryPool*>(::new char[realSize]);
        tmpLink = m_FreePos;

        //把分配出来的这一大块内存(m_sTrunkCount 小块)，彼此要链接起来，供后续使用
        for(; tmpLink != &m_FreePos[m_sTrunkCount - 1]; ++tmpLink){
            tmpLink->next = tmpLink + 1;
        }
        tmpLink->next = nullptr;
        ++m_iMallocCount;
    }
    tmpLink = m_FreePos;
    m_FreePos = m_FreePos->next;
    ++m_iCount;
    return tmpLink;
}

void MemoryPool::operator delete(void *phead)
{
    (static_cast<MemoryPool*>(phead))->next = m_FreePos;
    m_FreePos = static_cast<MemoryPool*>(phead);
}


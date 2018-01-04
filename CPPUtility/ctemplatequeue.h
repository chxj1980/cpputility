#ifndef CTEMPLATEQUEUE_H
#define CTEMPLATEQUEUE_H

#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>

namespace Cs {
namespace NetGate {

template<class T>
class CTemplateQueue
{
public:
    CTemplateQueue();
    ~CTemplateQueue();

    void Clear();
    void Push(std::shared_ptr<T> item);
    std::shared_ptr<T> Pop();
    bool Empty();

private:
    std::recursive_mutex m_mutex;
    std::condition_variable m_condition;
    std::queue<std::shared_ptr<T>> m_queue;
};

template<class T>
CTemplateQueue<T>::CTemplateQueue()
{

}

template<class T>
CTemplateQueue<T>::~CTemplateQueue()
{

}

template<class T>
void CTemplateQueue<T>::Clear()
{
    std::unique_lock<std::recursive_mutex> lock(m_mutex);
    while(!m_queue.empty())
    {
        m_queue.pop();
    }
}

template<class T>
void CTemplateQueue<T>::Push(std::shared_ptr<T> item)
{
    std::unique_lock<std::recursive_mutex> lock(m_mutex);
    m_queue.push(item);
    m_condition.notify_all();
}

template<class T>
std::shared_ptr<T> CTemplateQueue<T>::Pop()
{
    std::unique_lock<std::recursive_mutex> lock(m_mutex);
//    m_condition.wait(lock, [&]() {return !m_queue.empty(); });
    auto item = m_queue.front();
    m_queue.pop();
    return item;
}

template<class T>
bool CTemplateQueue<T>::Empty()
{
    std::unique_lock<std::recursive_mutex> lock(m_mutex);
    return m_queue.empty();
}

} //namespace NetGate
} //namespace Cs

#endif // CTEMPLATEQUEUE_H

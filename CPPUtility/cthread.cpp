#include "cthread.h"


#include <iostream>

CThread::CThread()
    : m_isRunning(false)
{

}

CThread::~CThread()
{
    if(m_thread.joinable())
    {
        m_thread.join();
    }
}

void CThread::start()
{

#ifndef _POSIX_MONOTONIC_CLOCK
std::cout << "error" << std::endl;
#endif

    m_startmutex.lock();
    m_thread = std::thread(&CThread::thread, this);
    m_thread.detach();
}

bool CThread::isRunning()
{
    return m_isRunning;
}

bool CThread::isFinished()
{
    return !m_isRunning;
}

bool CThread::wait(unsigned long time)
{
    std::unique_lock<std::mutex> locker(m_startmutex);
    std::chrono::seconds cseconds(time);
    std::chrono::system_clock::time_point sctimepoint(cseconds);
    bool bWait = m_mutex.try_lock_until(sctimepoint);
    if(bWait)
        m_mutex.unlock();
    return bWait;
}

void CThread::sleep(unsigned long sec)
{
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}

void CThread::finished()
{
}

void CThread::thread()
{
    m_startmutex.unlock();
    std::unique_lock<std::timed_mutex> locker(m_mutex);
    m_isRunning = true;
    run();
    // finish
    finished();
    m_isRunning = false;
}

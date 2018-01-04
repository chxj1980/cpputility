#ifndef CTHREAD_H
#define CTHREAD_H

#include <thread>
#include <mutex>
#include <condition_variable>

class CThread
{
public:
    CThread();
    ~CThread();

    // 开启线程
    void start();

    // 线程是否运行
    bool isRunning();
    bool isFinished();

    bool wait(unsigned long time = -1);
    static void sleep(unsigned long sec);

protected:
    /**
     * @brief run a pure function to be executed in thread body
     */
    virtual void run() = 0;
    virtual void finished();

private:
    void thread();

private:
    bool m_isRunning;

    std::thread m_thread;
    std::mutex m_startmutex;
    std::timed_mutex m_mutex;
};

#endif // CTHREAD_H

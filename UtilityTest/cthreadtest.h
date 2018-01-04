#ifndef CTHREADTEST_H
#define CTHREADTEST_H

#include "cthread.h"

class CThreadTest : public CThread
{
public:
    CThreadTest(){}
    ~CThreadTest(){}

private:
    virtual void run();
};

#endif // CTHREADTEST_H

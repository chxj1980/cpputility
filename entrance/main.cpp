#include <iostream>

#include "cthreadtest.h"
#include "cdatetimetest.h"
#include "cstringtest.h"

using namespace std;

int main()
{
    {
        CThreadTest test;
        test.start();
        cout << "time=  " << time(nullptr) << endl;
        bool ret = test.wait(time(nullptr) + 10);
        cout << "time=  " << time(nullptr) << (ret ? ";  true" : ";  false") << endl;
    }

//    {
//        CDateTimeTest test;
//    }

//    {
//        CStringTest test;
//    }
    return 0;
}

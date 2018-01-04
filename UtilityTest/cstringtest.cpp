#include "cstringtest.h"

#include <iostream>

#include "cstring.h"

void CStringTest::Test()
{
    std::cout << "CStringTimeTest::Test--   " << CString::StrCmpCaseInsensitive("dec", "DEC") << std::endl;
    std::cout << "CStringTimeTest::Test--   " << CString::StrCmpCaseInsensitive("dec", "eEC") << std::endl;
    std::cout << "CStringTimeTest::Test--   " << CString::StrCmpCaseInsensitive("eec", "DEC") << std::endl;
    MYLOG("%s", "CStringTest::Hello!");
}

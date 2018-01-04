#include "cstring.h"

#ifdef __linux
#include <strings.h>
#else
#include <string.h>
#endif

#include <stdio.h>
#include <functional>
#include <algorithm>
#include <ctime>

int CString::StrCmpCaseInsensitive(const char *str1, const char *str2)
{
    int ret = 0;
#ifdef __linux
    ret = strcasecmp(str1, str2);
#else
    ret = stricmp(str1, str2);
#endif
    return ret;
}

int CString::NumberToString(char *str, int num, const char * format)
{
    str = new char[20]();
    return sprintf(str, format, num);
}

int CString::StringToNumber(const char *str, uint16_t &num)
{
    return sscanf(str, "%" SCNu16, &num);
}

int CString::StringToNumber(const char *str, int &num, const char *format)
{
    return sscanf(str, format, &num);
}

int CString::StringToNumber(const char *str, long &num, const char *format)
{
    return sscanf(str, format, &num);
}

int CString::StringToNumber(const char *str, long long &num, const char *format)
{
     return sscanf(str, format, &num);
}

int CString::split(const std::string &str, std::vector<std::string> &ret, std::string sep, comparePtr cmpPtr)
{
    if(str.empty())
        return 0;
    std::string tmp;
    std::string::size_type pos_begin = str.find_first_not_of(sep);
    std::string::size_type comma_pos = 0;
    while(pos_begin != std::string::npos)
    {
        comma_pos = str.find(sep, pos_begin);
        if(comma_pos != std::string::npos)
        {
            tmp = str.substr(pos_begin, comma_pos - pos_begin);
            pos_begin = comma_pos + sep.length();
        }
        else
        {
            tmp = str.substr(pos_begin);
            pos_begin = comma_pos;
        }

        if(!tmp.empty())
        {
            ret.push_back(tmp);
            tmp.clear();
        }
    }
    if(cmpPtr != nullptr)
    {
       std::sort(ret.begin(), ret.end(), cmpPtr);
    }
    return ret.size();
}

std::string CString::StrToUpper(const std::string &s)
{
    std::string result(s);
    std::transform(
      s.begin(),
      s.end(),
      result.begin(),
      std::ptr_fun<int, int>(std::toupper)
      );
    return result;
}

int CString::GetRandomNumber()
{
    int nRandom = 0;
    time_t t;
    srand((unsigned)time(&t));
    nRandom = rand();
    MYLOG("%s:%d\n", "Get random number", nRandom);
    return  nRandom;
}

bool CString::Startwith(const std::string &str, const std::string &startStr)
{
    if(startStr.size() > str.size() )
        return false;
    return str.substr(0,startStr.size()) == startStr;
}

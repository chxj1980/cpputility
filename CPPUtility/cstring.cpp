#include "cstring.h"

#ifdef __linux__
#include <strings.h>
#endif

#include <stdio.h>

int CString::StrCmpCaseInsensitive(const char *str1, const char *str2)
{
    int ret = 0;
#ifdef __linux__
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

int CString::StringToNumber(const char *str, int num, const char *format)
{
    return sscanf(str, format, num);
}

#ifndef CSTRING_H
#define CSTRING_H

#include <stdio.h>

#define MYLOG(fmt, ...) printf("File %s line %d: " fmt "\n", __FILE__, __LINE__, __VA_ARGS__)

namespace CString
{
    int StrCmpCaseInsensitive(const char *str1, const char *str2);
    int NumberToString(char *str, int num, const char *format = "%d");
    int StringToNumber(const char *str, int num, const char *format = "%d");
} //namespace CString

#endif // CSTRING_H

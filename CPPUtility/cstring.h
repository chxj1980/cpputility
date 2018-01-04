#ifndef CSTRING_H
#define CSTRING_H

#include <stdio.h>
#include <string>
#include <vector>
#include <cinttypes>

#define MYLOG(fmt, ...) printf("File %s line %d: " fmt "\n", __FILE__, __LINE__, __VA_ARGS__)

typedef bool comparePtr(std::string , std::string );

namespace CString
{
    int StrCmpCaseInsensitive(const char *str1, const char *str2);
    int NumberToString(char *str, int num, const char *format = "%d");
    int StringToNumber(const char *str, uint16_t &num);
    int StringToNumber(const char *str, int &num, const char *format = "%d");
    int StringToNumber(const char *str, long &num, const char *format = "%ld");
    int StringToNumber(const char *str, long long &num, const char *format = "%lld");
    int split(const std::string &str, std::vector<std::string>& ret, std::string sep, comparePtr cmpPtr = nullptr);
    std::string StrToUpper(const std::string& s);
    bool Startwith(const std::string &str, const std::string &startStr);
    int GetRandomNumber();
} //namespace CString

#endif // CSTRING_H

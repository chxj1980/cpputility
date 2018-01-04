#include "cdatetime.h"

#include <string.h>
#include <time.h>
#include <chrono>
#include <sys/time.h>

bool CDateTime::GetCurrentDateTime(std::string &strtime, std::string strformat)
{
    long timestamp = std::time(nullptr);
    return GetTimeAsString(strtime, strformat, timestamp);
}

bool CDateTime::GetTimeAsString(std::string &strtime, std::string strformat, long timestamp)
{
    char buffer[30];
    memset(buffer, 0, sizeof(buffer));

    std::chrono::seconds cseconds(timestamp);
    std::chrono::system_clock::time_point sctimepoint(cseconds);
    std::time_t ttime = std::chrono::system_clock::to_time_t(sctimepoint);
    std::tm tmres;
    localtime_r(&ttime, &tmres);
    std::strftime(buffer, 30, strformat.c_str(), &tmres);

    strtime = std::string(buffer);
    return true;
}

bool CDateTime::GetTimeFromString(std::string strtime, long &timestamp, std::string strFormat)
{
    int nyear, nmon, nday, nhou, nmin, nsec;

    sscanf(strtime.c_str(), strFormat.c_str(), &nyear, &nmon, &nday, &nhou, &nmin, &nsec);
    std::tm stimeinfo;
    stimeinfo.tm_year = nyear-1900;
    stimeinfo.tm_mon = nmon-1;
    stimeinfo.tm_mday = nday;
    stimeinfo.tm_hour = nhou;
    stimeinfo.tm_min = nmin;
    stimeinfo.tm_sec = nsec;

    timestamp = std::mktime(&stimeinfo);
    return true;
}

int CDateTime::GetDiffDay(long starttime, long endtime)
{
    double diffsec = std::difftime(endtime, starttime);
    int diffday = diffsec / (24 * 3600);
    return diffday;
}

bool CDateTime::GetCurrentDateTimeToMircosecond(std::string &strtime, std::string strformat)
{
    struct timeval tv;
    gettimeofday(&tv, nullptr);
//    long timestamp = std::time(nullptr);
    bool result = GetTimeAsString(strtime, strformat, tv.tv_sec);
    std::string usec = std::to_string(tv.tv_usec);
    std::string zeroSTr;
    zeroSTr.append(6-usec.size(),'0');
    strtime = strtime + " " + zeroSTr + usec;
    return result;
}

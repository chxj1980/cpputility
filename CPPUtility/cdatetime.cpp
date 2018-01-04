#include "cdatetime.h"

#include <string.h>
#include <time.h>
#include <chrono>

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
    std::strftime(buffer, 30, strformat.data(), &tmres);

    strtime = std::string(buffer);
    return true;
}

bool CDateTime::GetTimeFromString(std::string strtime, long &timestamp)
{
    int nyear, nmon, nday, nhou, nmin, nsec;

    sscanf(strtime.data(), "%d-%d-%dT%d:%d:%d", &nyear, &nmon, &nday, &nhou, &nmin, &nsec);
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

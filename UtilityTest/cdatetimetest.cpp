#include "cdatetimetest.h"

#include <chrono>
#include <iostream>

#include "cdatetime.h"

void CDateTimeTest::Test()
{
    // get current time
    std::string curtime;
    CDateTime::GetCurrentDateTime(curtime, "%FT%T");
    std::cout << "CDateTimeTest::Test--curtime=[" << curtime << "]" << std::endl;

    // get request parameters
    std::string starttime = "2010-11-11T19:46:17";
    std::string endtime = "2010-11-12T19:46:17";

    // get seconds_since_epoch for starttime and endtime
    long scount=-1, ecount=-1;
    CDateTime::GetTimeFromString(starttime, scount);
    CDateTime::GetTimeFromString(endtime, ecount);
    std::cout << "CDateTimeTest::Test--scount=" << scount << ";ecount=" << ecount << std::endl;

    std::string tableName;
    std::chrono::system_clock::time_point stimepoint = std::chrono::system_clock::from_time_t(scount);

    int diffday = CDateTime::GetDiffDay(scount, ecount);
    for(int i=-1; i<=diffday && diffday>=0; i++)
    {
        tableName.clear();
        std::chrono::hours oneday(i*24);
        std::chrono::system_clock::time_point itimepoint = stimepoint + oneday;
        time_t itime = std::chrono::system_clock::to_time_t(itimepoint);
        CDateTime::GetTimeAsString(tableName, "S%G%m%d", itime);

        std::cout << "CDateTimeTest::Test--table name: " << tableName << std::endl;
    }

    long timestamp = 1499258297;
    std::string stimetamsp;
    CDateTime::GetTimeAsString(stimetamsp, "%FT%T", timestamp);
    std::cout << "CDateTimeTest::Test--stimestamp=" << stimetamsp << std::endl;
}

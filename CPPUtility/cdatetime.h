#ifndef CDATETIME_H
#define CDATETIME_H

#include <string>

namespace CDateTime {
    /**
     * @brief GetCurrentDateTime    transform current timestamp into strtime according to strformat
     * @param strtime               formatted string
     * @param strformat             format, referring to format of 'std::strftime()'
     * @return
     */
    bool GetCurrentDateTime(std::string &strtime, std::string strformat);

    /**
     * @brief GetTimeAsString   transform timestamp into strtime according to strformat
     * @param strtime           formatted string
     * @param strformat         format, referring to format of 'std::strftime()'
     * @param timestamp         given time
     * @return
     */
    bool GetTimeAsString(std::string &strtime, std::string strformat, long timestamp);

    /**
     * @brief GetTimeFromString transform strtime into timestamp according to strformat
     * @param strtime           given string of time, "yyyy-mm-ddThh:mm:ss"
     * @param timestamp         requested time
     * @return
     */
    bool GetTimeFromString(std::string strtime, long &timestamp, std::string strFormat = "%d-%d-%dT%d:%d:%d");

    /**
     * @brief GetDiffDay        calculate different day from starttime to endtime
     * @param starttime         start timestamp
     * @param endtime           end timestamp
     * @return
     */
    int GetDiffDay(long starttime, long endtime);

    bool GetCurrentDateTimeToMircosecond(std::string &strtime ,std::string strformat);

} //namespace CDateTime

#endif // CDATETIME_H

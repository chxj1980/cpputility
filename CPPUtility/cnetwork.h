#ifndef CNETWORK_H
#define CNETWORK_H

#include <string>

namespace CNetwork
{
    std::string HostOrderToString(unsigned int hostOrder);
    unsigned int StringToHostOrder(std::string hostString);
}

#endif // CNETWORK_H

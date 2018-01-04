#include "cnetwork.h"

#ifdef __linux
#include <arpa/inet.h>
#elif __WIN32__
#include <winsock2.h>
#endif

std::string CNetwork::HostOrderToString(unsigned int hostOrder)
{
    in_addr tmp;
    tmp.s_addr = htonl(hostOrder);
    return inet_ntoa(tmp);
}

unsigned int CNetwork::StringToHostOrder(std::string hostString)
{
    return ntohl(inet_addr(hostString.c_str()));
}

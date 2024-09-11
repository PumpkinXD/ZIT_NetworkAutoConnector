#ifndef UTF8STRING_HANDLE
#define UTF8STRING_HANDLE
#include <cstdlib>
#include <cstring>
#include <cuchar>
#include <stdexcept>
#include <string>
#include <vector>

namespace io_github_pumpkinxd_ZitNetworkAutoConnector
{

std::vector<std::string> splitString(const std::string &in);
std::string extractQueryString(const std::string &url);
} // namespace io_github_pumpkinxd_ZitNetworkAutoConnector

#endif /* UTF8STRING_HANDLE */

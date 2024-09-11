#include "utf8string_handle.hpp"

namespace io_github_pumpkinxd_ZitNetworkAutoConnector
{
std::vector<std::string> splitString(const std::string &in)
{
    // std::setlocale(LC_ALL, "");
    std::mbstate_t mb = std::mbstate_t();
    std::vector<std::string> ret;
    const char *ptr = in.data();
    const char *const end = ptr + in.size();

    while (ptr < end)
    {
        std::size_t next = std::mbrlen(ptr, end - ptr, &mb);
        if (next == (std::size_t)-1)
            throw std::runtime_error("strlen_mb(): conversion error");
        if (next == (std::size_t)-2)
            throw std::runtime_error("strlen_mb(): incomplete multibyte sequence");
        if (next == 0)
            break;

        ret.push_back(std::string(ptr, next));
        ptr += next;
    }

    return ret;
}
std::string extractQueryString(const std::string &url)
{
    size_t start = url.find('?');
    if (start == std::string::npos)
    {
        return "";
    }
    return url.substr(start + 1);
}
} // namespace io_github_pumpkinxd_ZitNetworkAutoConnector

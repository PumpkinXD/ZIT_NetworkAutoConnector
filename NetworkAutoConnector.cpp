#include "NetworkAutoConnector.hpp"
#include "NetworkHandler.hpp"
#include <asm-generic/errno.h>
#include <json/json.h>
#include <sys/socket.h>

bool io_github_pumpkinxd_ZitNetworkAutoConnector::NetworkAutoConnector::isOnline()
{
    return this->online;
}
io_github_pumpkinxd_ZitNetworkAutoConnector::NetworkAutoConnector::NetworkAutoConnector()
{
}
io_github_pumpkinxd_ZitNetworkAutoConnector::NetworkAutoConnector::NetworkAutoConnector(const std::string &filename)
{
}
void io_github_pumpkinxd_ZitNetworkAutoConnector::NetworkAutoConnector::saveConfig2file(const std::string &filename)
{
}
void io_github_pumpkinxd_ZitNetworkAutoConnector::NetworkAutoConnector::fetchPortalUrlAndQuery()
{
    if (!isOnline())
    {
        auto respond = io_github_pumpkinxd_ZitNetworkAutoConnector::http_get("http://networkcheck.kde.org/", "");
        if (!respond.empty())
        {
        }
    }
};
void io_github_pumpkinxd_ZitNetworkAutoConnector::NetworkAutoConnector::updateOnlineStats()
{
    auto respond = http_get("http://networkcheck.kde.org/", "");
    if (respond == "OK")
    {
        this->online = true;
    }
    else if (!respond.empty())
    {
        // on zit network but not login?
        this->online = false;

        if (!this->PortalUrl.empty())
        {
            zit_online = -1;
        }
        else
        {
            zit_online = -2;
        }
    }
    else
    {
        online = 0;
        zit_online = 0;
    }
};
#ifndef NETWORKHANDLER
#define NETWORKHANDLER

#include <arpa/inet.h>
#include <cerrno>
#include <csignal>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <thread>
#include <unistd.h>
#include <vector>
// #include <pthread.h>

namespace io_github_pumpkinxd_ZitNetworkAutoConnector
{

std::string http_get(const std::string &hostname, const std::string &content);
}

#endif /* NETWORKHANDLER */

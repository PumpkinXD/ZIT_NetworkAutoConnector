#ifndef NETWORKHANDLER
#define NETWORKHANDLER



#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <sys/types.h>

#include <fcntl.h>
#include <netdb.h>

#include <ctime>
#include <cerrno>
#include <csignal>
#include <cstdlib>
#include <cstring>
#include <thread>
#include <string>
#include <vector>
// #include <pthread.h>



namespace io_github_pumpkinxd_ZitNetworkAutoConnector {

std::string http_get(const std::string &hostname,
                     const std::string content = "");
}

#endif /* NETWORKHANDLER */

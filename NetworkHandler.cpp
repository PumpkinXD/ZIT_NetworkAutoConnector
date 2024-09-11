#include "NetworkHandler.hpp"
#include <string>
const auto port = 80;
const auto buffersize = 1024;

static int http_create_socket(char *ip); // https://gao377020481.github.io/p/http%E5%AE%A2%E6%88%B7%E7%AB%AF/
static char *host_to_ip(const char *hostname);
static char *http_send_request(const char *hostname, const char *resource);
static char *http_send_request2(const char *hostname, const char *resource, bool use_post_instead_get);

std::string io_github_pumpkinxd_ZitNetworkAutoConnector::http_get(const std::string &hostname,
                                                                  const std::string &content = "")
{

    auto res=http_send_request2(hostname.c_str(), content.c_str(), false);
    std::string respond=res;
    std::free(res);
    //
    return respond;
}

// use std::free() to release
[[nodiscard("Causing Memory Leak if you discard it's ret")]] static char *http_send_request(const char *hostname,
                                                                                            const char *resource)
{
    const auto BUFFER_SIZE = 4096;
    const auto HTTP_VERSION = "HTTP/1.1";
    const auto CONNECTION_TYPE = "Keep-Alive";

    char *ip = host_to_ip(hostname); //
    int sockfd = http_create_socket(ip);

    char buffer[BUFFER_SIZE] = {0};
    sprintf(buffer, "GET %s %s\r\n\
Host: %s\r\n\
%s\r\n\
\r\n",

            resource, HTTP_VERSION, hostname, CONNECTION_TYPE);

    send(sockfd, buffer, strlen(buffer), 0);

    // select

    fd_set fdread;

    FD_ZERO(&fdread);
    FD_SET(sockfd, &fdread);

    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    char *result = (char *)std::malloc(sizeof(int));
    memset(result, 0, sizeof(int));

    while (1)
    {

        int selection = select(sockfd + 1, &fdread, NULL, NULL, &tv);
        if (!selection || !FD_ISSET(sockfd, &fdread))
        {
            break;
        }
        else
        {

            memset(buffer, 0, BUFFER_SIZE);
            int len = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (len == 0)
            { // disconnect
                break;
            }

            result = (char *)realloc(result, (strlen(result) + len + 1) * sizeof(char));
            strncat(result, buffer, len);
        }
    }

    return result;
}

[[nodiscard("Causing Memory Leak if you discard it's ret")]] static char *http_send_request2(
    const char *hostname, const char *resource, bool use_post_instead_get = false)
{
    const auto BUFFER_SIZE = 4096;
    const auto HTTP_VERSION = "HTTP/1.1";
    const auto CONNECTION_TYPE = "Keep-Alive";

    char *ip = host_to_ip(hostname); //
    int sockfd = http_create_socket(ip);

    char buffer[BUFFER_SIZE] = {0};
    if (use_post_instead_get)
    {

        sprintf(buffer, "POST %s %s\r\n\
Host: %s\r\n\
%s\r\n\
\r\n",

                resource, HTTP_VERSION, hostname, CONNECTION_TYPE);
    }
    else
    {
        sprintf(buffer, "GET %s %s\r\n\
Host: %s\r\n\
%s\r\n\
\r\n",

                resource, HTTP_VERSION, hostname, CONNECTION_TYPE);
    }

    send(sockfd, buffer, strlen(buffer), 0);

    // select

    fd_set fdread;

    FD_ZERO(&fdread);
    FD_SET(sockfd, &fdread);

    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    char *result = (char *)std::malloc(sizeof(int));
    memset(result, 0, sizeof(int));

    while (1)
    {

        int selection = select(sockfd + 1, &fdread, NULL, NULL, &tv);
        if (!selection || !FD_ISSET(sockfd, &fdread))
        {
            break;
        }
        else
        {

            memset(buffer, 0, BUFFER_SIZE);
            int len = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (len == 0)
            { // disconnect
                break;
            }

            result = (char *)realloc(result, (strlen(result) + len + 1) * sizeof(char));
            strncat(result, buffer, len);
        }
    }

    return result;
}

static int http_create_socket(char *ip)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in sin = {0};
    sin.sin_family = AF_INET;
    sin.sin_port = htons(80);
    sin.sin_addr.s_addr = inet_addr(ip);

    if (0 != connect(sockfd, (struct sockaddr *)&sin, sizeof(struct sockaddr_in)))
    {
        return -1;
    }
    fcntl(sockfd, F_SETFL, O_NONBLOCK);

    return sockfd;
}

static char *host_to_ip(const char *hostname)
{
    struct hostent *host_entry = gethostbyname(hostname);

    if (host_entry)
    {
        return inet_ntoa(*(struct in_addr *)*host_entry->h_addr_list);
    }
    return NULL;
}

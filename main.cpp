#include "NetworkHandler.hpp"
#include <atomic>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

std::thread worker;
std::atomic_bool running = false;

void worker_func();

int main()
{
    worker = std::thread(worker_func);
    std::cout << "hello\n";

    worker.join();
}

void worker_func()
{

    while (running)
    {
        std::string respond = io_github_pumpkinxd_ZitNetworkAutoConnector::http_get("http://networkcheck.kde.org/", "");

        //...
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
}
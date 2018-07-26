//
// Created by lizhaoyu on 7/25/18.
//

#include "Server.h"

#include <iostream>
#include <boost/thread.hpp>
#include <future>
#include <chrono>
#include <mutex>

using namespace std;

Server::Server(const int &Id) {
    cout << "Server Server()...\n";
    serverId = Id;
    start();
}

Server::~Server() {
    cout << "~Server()...\n";
}

void Server::start() {
    cout << "Server start()...\n";
}

void Server::shutdown() {
    cout << "Server shutdown()...\n";
}

void Server::stop() {
    cout << "Sever stop()...\n";
}
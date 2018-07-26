//
// Created by lizhaoyu on 7/23/18.
//

#ifndef RAFT_SERVER_H
#define RAFT_SERVER_H

#include <vector>
#include <iostream>

#include "Raft.h"

class  Server{
private:
    int serverId;

    Raft raft;

public:
    Server() = delete;
    explicit Server(const int &Id);
    ~Server();
    void start();
    void stop();
    void shutdown();
};


#endif //RAFT_SERVER_H

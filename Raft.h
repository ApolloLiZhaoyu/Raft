//
// Created by lizhaoyu on 7/25/18.
//

#ifndef RAFT_RAFT_H
#define RAFT_RAFT_H

#include <thread>

#include "Event_Queue.h"
#include "State.h"
#include "Timer.h"
#include "AppendEntries_ RPC.h"
#include "RequestVote_RPC.h"
#include "Identity.h"

class Raft{
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    Raft();
    ~Raft();
    void start();
    void shutdown();
    void stop();

};


#endif //RAFT_RAFT_H

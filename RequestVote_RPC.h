//
// Created by lizhaoyu on 7/24/18.
//

#ifndef RAFT_REQUESTVOTE_RPC_H
#define RAFT_REQUESTVOTE_RPC_H

#include <thread>

class RequestVote_RPC{
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
    int term;
    int candidateId;
    int lastLogIndex;
    int lastLogTerm;

public:
    RequestVote_RPC();
    ~RequestVote_RPC();

};

#endif //RAFT_REQUESTVOTE_RPC_H

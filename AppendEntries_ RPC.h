//
// Created by lizhaoyu on 7/24/18.
//

#ifndef RAFT_APPENDENTRIES_RPC_H
#define RAFT_APPENDENTRIES_RPC_H

#include <vector>
#include <thread>

class AppendEntries_RPC {
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

    int term;
    int leaderId;
    int prevLogIndex;
    int prevLogTerm;
    int leaderCommit;
    //std::vector <std::pair<void(), int>> entries;

public:
    AppendEntries_RPC();
    ~AppendEntries_RPC();
};

#endif //RAFT_APPENDENTRIES_RPC_H

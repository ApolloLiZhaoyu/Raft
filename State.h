//
// Created by lizhaoyu on 7/24/18.
//

#ifndef RAFT_STATE_H
#define RAFT_STATE_H

#include <vector>
#include <thread>
#include <memory>
#include <functional>

class State{
public:
    State();
    ~State();
    void bind(std::function <void()> func, int serverstate);
    void update_commitIndex();
    void update_lastApplied();

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

    int currentTerm;
    int votedFor;
//    std::vector <std::pair<void(), int>>  entries;

    int commitIndex;
    int lastApplied;

    std::vector <int> nextIndex;
    std::vector <int> matchIndex;
};


#endif //RAFT_STATE_H

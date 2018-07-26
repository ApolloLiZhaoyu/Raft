//
// Created by lizhaoyu on 7/23/18.
//

#ifndef RAFT_TIMER_H
#define RAFT_TIMER_H

#include <thread>
#include <functional>

class Timer{
private:
    struct Impl;
    int election_timeout;
    bool timeout;
    std::unique_ptr<Impl> pImpl;

public:
    Timer();
    ~Timer();
    inline void init();
    inline void start();
    void stop();
    void reset();
    void run();
    void bind(std::function <void()> func);
    void test();
};

#endif //RAFT_TIMER_H

//
// Created by lizhaoyu on 7/25/18.
//

#ifndef RAFT_EVENT_QUEUE_H
#define RAFT_EVENT_QUEUE_H

#include <memory>
#include <functional>

class Event_Queue{
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    Event_Queue();
    ~Event_Queue();
    void add_event(std::function <void()> func);
    void start();
    void stop();
    //void reset();
    //void wait();

};


#endif //RAFT_EVENT_QUEUE_H

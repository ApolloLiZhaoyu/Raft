//
// Created by lizhaoyu on 7/25/18.
//

#include "Raft.h"

#include <iostream>
#include <boost/thread.hpp>

struct Raft::Impl {
    boost::mutex m;
    std::function<void()> func = nullptr;
    boost::thread t;

    Event_Queue event_queue;

    State state;

    std::vector <int> votes;

    Timer timer;

    AppendEntries_RPC appendEntries_rpc;
    RequestVote_RPC requestVote_rpc;

    int identity = 0; // 1 : follower; 2 : candidate; 3 : leader

    Identity_Leader leader;
    Identity_Follower follower;
    Identity_Candidate candidate;

    void test(){
        std::cout << "timer lose heartbeat...\n";
    }

    void start() {
        timer.bind(std::bind(&Raft::Impl::test, this));
        timer.run();
    }

    void stop() {
        timer.stop();
        event_queue.stop();
    }

    void shutdown() {

    }

    void become_leader() {
        identity = 3;
    }

    void become_candidate() {
        identity = 2;
    }

    void become_follower() {
        identity = 1;
    }

};


Raft::Raft() : pImpl(std::make_unique <Raft::Impl> ()){
    start();
};

Raft::~Raft() {
    stop();
};

void Raft::start() {
    std::cout << "Raft start()...\n";
    pImpl->start();
}

void Raft::shutdown() {
    std::cout << "Raft shutdown()...\n";
    pImpl->shutdown();
}

void Raft::stop() {
    std::cout << "Raft stop()...\n";
    pImpl->stop();
}
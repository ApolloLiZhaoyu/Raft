//
// Created by lizhaoyu on 7/23/18.
//

#ifndef RAFT_IDENTITY_H
#define RAFT_IDENTITY_H

#include <memory>

class Identity_Candidate {
private:
    /*struct Impl;
    std::unique_ptr<Impl> pImpl;*/
public:
    Identity_Candidate() = default;

    ~Identity_Candidate() = default;

    void init() {};

    void increment_currentTerm() {};

    void vote_for_self() {};

    void reset_election_timer() {};

    void send_RequestVote_RPC() {};
};

class Identity_Follower {
private:
    /*struct Impl;
    std::unique_ptr<Impl> pImpl;*/
public:
    ~Identity_Follower() = default;
    Identity_Follower() = default;
    void respond_to_RPC() {};
    void convert_to_candidate() {};
};

class Identity_Leader {
private:
    /*struct Impl;
    std::unique_ptr<Impl> pImpl;*/
public:
    ~Identity_Leader() = default;
    Identity_Leader() = default;
    void send_heartbeat_to_each_server() {};
    void command_received_from_client() {};

};



#endif //RAFT_IDENTITY_H

//
// Created by lizhaoyu on 7/24/18.
//

#include "State.h"
#include <boost/thread.hpp>

struct State::Impl {

};

void State::bind(std::function<void()> func, int serverstate) {

}

void State::update_commitIndex() {

}

void State::update_lastApplied() {

}

State::State() = default;

State::~State() = default;
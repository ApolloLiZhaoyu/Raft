//
// Created by lizhaoyu on 7/24/18.
//

#include <iostream>
#include <algorithm>
#include <boost/thread.hpp>
#include <future>
#include <chrono>
#include <mutex>
#include <memory>

#include "Timer.h"


struct Timer::Impl{
    boost::mutex m;
    std::function<void()> func = nullptr;
    boost::thread t;
};

Timer::Timer() : pImpl(std::make_unique <Timer::Impl> ()){
    init();
    start();
}

Timer::~Timer(){
    stop();
}

void Timer::bind(std::function <void()> func){
    pImpl->func = std::move(func);
}

inline void Timer::init() {
    election_timeout = rand() % 150 + 150;
    std::cout << "Timer_election_timeout = " << election_timeout << '\n';
}

inline void Timer::start() {
    timeout = 0;
}

void Timer::stop(){
    pImpl->t.interrupt();
    pImpl->t.join();
    timeout = 1;
}

void Timer::reset(){
    stop();
    start();
    run();
}

void Timer::run(){
    std::cout << "Timer run()..." << '\n';
    boost::unique_lock<boost::mutex> lk(pImpl->m, boost::defer_lock);
    pImpl->t = boost::thread([lk = std::move(lk), func = pImpl->func, election_timeout = election_timeout, timeout = timeout] {
        boost::this_thread::disable_interruption d;
        do{
            try{
                boost::this_thread::restore_interruption ri(d);
                boost::this_thread::sleep_for(boost::chrono::milliseconds(election_timeout));
            }
            catch (boost::thread_interrupted) {
                return;
            }
            func();
        } while(!timeout);
    });
}

//
// Created by lizhaoyu on 7/25/18.
//

#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread_only.hpp>
#include <boost/thread/lock_guard.hpp>
#include <boost/thread/locks.hpp>
#include <boost/thread/condition_variable.hpp>
#include <queue>
#include <iostream>

#include "Event_Queue.h"

struct Event_Queue::Impl{

    struct event{
        int eventIdx;
        std::function <void()> func;
    };

    std::queue <event> q;
    int curIdx = 0;

    boost::thread t;
    boost::mutex m;
    boost::condition_variable cv;

    void add_event(std::function<void()> func) {
        boost::lock_guard<boost::mutex> lk(m);
        q.push({++curIdx, std::move(func)});
        cv.notify_all();
    }

    void run() {
        std::cout << "Event_Queue is waiting!!!" << '\n';
        while (true) {
            boost::unique_lock <boost::mutex> lk(m);
            try {
                cv.wait(lk, [this] { return !q.empty(); });
            }
            catch (boost::thread_interrupted) {
                std::cout << "event_queue interrupt\n";
                return;
            }
            auto event = q.front();
            q.pop();
            lk.unlock();

            boost::this_thread::disable_interruption d;
            event.func();

            cv.notify_all();
        }
    }

    void start() {
        if (t.joinable())
            return;
        t = boost::thread(std::bind(&Event_Queue::Impl::run, this));
    }

    void stop() {
        t.interrupt();
        t.join();
    }
};

Event_Queue::Event_Queue() : pImpl(std::make_unique <Event_Queue::Impl> ()){
    start();
}

Event_Queue::~Event_Queue() {
    stop();
}

void Event_Queue::start() {
    std::cout << "Event_Queue start()...\n";
    pImpl->start();
}

void Event_Queue::stop() {
    std::cout << "Event_Queue stop()...\n";
    pImpl->stop();
}

void Event_Queue::add_event(std::function<void()> func) {
    pImpl->add_event(std::move(func));
}


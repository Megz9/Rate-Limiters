//
// Created by abdel on 9/13/2024.
//

#ifndef RATE_LIMITERS_SLIDINGWINDOWCOUNTER_H
#define RATE_LIMITERS_SLIDINGWINDOWCOUNTER_H

#include<iostream>
#include <deque>
#include<thread>
#include<chrono>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

class slidingWindowCounter {
private:
    int maxRequests;
    int windowSizeSec;
    deque<high_resolution_clock::time_point> requestTimeStamps;
public:
    slidingWindowCounter(int maxReq, int windowSizeSec):maxRequests(maxReq), windowSizeSec(windowSizeSec)
    {}

    bool allowRequest();
};


#endif //RATE_LIMITERS_SLIDINGWINDOWCOUNTER_H

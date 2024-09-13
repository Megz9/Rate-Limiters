//
// Created by abdel on 9/13/2024.
//

#ifndef RATE_LIMITERS_FIXEDWINDOWCOUNTER_H
#define RATE_LIMITERS_FIXEDWINDOWCOUNTER_H

#include<iostream>
#include<thread>
#include<chrono>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

class FixedWindowCounter {
private:
    int windowSizeSec;
    int requestCount;
    int maxRequests;
    high_resolution_clock::time_point windowStart;

    void ResetWindowIfNeeded();
public:
    FixedWindowCounter(int requests=5, int rate=1):windowSizeSec(requests), maxRequests(rate), requestCount(0)
    {
        windowStart = high_resolution_clock::now();
    }
    bool allowRequest();
};


#endif //RATE_LIMITERS_FIXEDWINDOWCOUNTER_H

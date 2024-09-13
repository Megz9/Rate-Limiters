//
// Created by abdel on 9/13/2024.
//

#ifndef RATE_LIMITERS_LEAKYBUCKET_H
#define RATE_LIMITERS_LEAKYBUCKET_H

#include<iostream>
#include<thread>
#include<chrono>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

class LeakyBucket{
private:
    int rate;
    int maxBucketSize;
    int currentBucket;
    high_resolution_clock::time_point lastLeakTime;

    void leakTokens();

public:
    LeakyBucket(int r= 1, int d=5)
            : rate(r), maxBucketSize(d), currentBucket(0)
    {
        lastLeakTime = high_resolution_clock::now();
    }

    bool addRequest();
};

#endif //RATE_LIMITERS_LEAKYBUCKET_H

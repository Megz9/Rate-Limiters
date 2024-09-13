//
// Created by abdel on 9/13/2024.
//

#ifndef RATE_LIMITERS_TOKENBUCKET_H
#define RATE_LIMITERS_TOKENBUCKET_H


#include<iostream>
#include<thread>
#include<chrono>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

class TokenBucket{
private:
    int rate;
    int maxBucketSize;
    int currentBucket;
    high_resolution_clock::time_point currentTime;
    void refillBucket();
public:
    TokenBucket(int r= 10, int BS=5)
            : rate(r), maxBucketSize(BS), currentBucket(BS)
    {
        currentTime=high_resolution_clock::now();
    }
    bool requestToken();


};



#endif //RATE_LIMITERS_TOKENBUCKET_H

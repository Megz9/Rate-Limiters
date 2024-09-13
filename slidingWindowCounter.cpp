//
// Created by abdel on 9/13/2024.
//

#include "slidingWindowCounter.h"
bool slidingWindowCounter::allowRequest(){
    high_resolution_clock::time_point  now= high_resolution_clock::now();

    while(!requestTimeStamps.empty()){
        double elapsedTime = duration_cast<seconds>(now-requestTimeStamps.front()).count();
        if(elapsedTime >= windowSizeSec){
            requestTimeStamps.pop_front();
        }else{
            break;
        }
    }

    if(requestTimeStamps.size()<maxRequests){
        requestTimeStamps.push_back(now);
        cout<< "Request allowed\n";
        return true;
    }else{
        cout<< "Request denied\n";
        return false;
    }
}
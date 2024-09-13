//
// Created by abdel on 9/13/2024.
//

#include "FixedWindowCounter.h"

void FixedWindowCounter::ResetWindowIfNeeded(){
    high_resolution_clock::time_point windowNow= high_resolution_clock::now();
    double elapsedWindow = duration_cast<milliseconds>(windowNow-windowStart).count();
    if(elapsedWindow>=windowSizeSec){
        requestCount=0;
        windowStart = windowNow;
        cout << "Window reset. Starting a new window.\n";
    }
}

bool FixedWindowCounter::allowRequest(){
    ResetWindowIfNeeded();

    if(requestCount<maxRequests){
        requestCount++;
        cout<< " request allowed Current count: " << requestCount << "\n";
        return true;
    }else {
        cout << "Request denied. Limit reached for this window.\n";
        return false;
    }
}
//
// Created by abdel on 9/13/2024.
//

#include "TokenBucket.h"

void TokenBucket::refillBucket(){
    high_resolution_clock::time_point newTime=high_resolution_clock::now();
    double diff= duration_cast<milliseconds>(newTime - currentTime).count();
    if( diff>rate){

        currentTime=newTime;
        currentBucket=maxBucketSize;
    }
}

bool TokenBucket::requestToken(){
    refillBucket();
    if(currentBucket){
        currentBucket--;
        cout<< "token consumed\n";
        return true;
    }
    cout<< "no tokens available\n";
    return false;
}

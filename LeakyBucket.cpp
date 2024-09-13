//
// Created by abdel on 9/13/2024.
//

#include "LeakyBucket.h"

void LeakyBucket::leakTokens(){
    high_resolution_clock::time_point now = high_resolution_clock::now();
    double elapsedTime = duration_cast<seconds>(now-lastLeakTime).count();
    int tokensToLeak = static_cast<int>(elapsedTime* rate);
    if(tokensToLeak >0){
        currentBucket = max(0, currentBucket - tokensToLeak);
        lastLeakTime = now;
        cout <<"leaked "<< tokensToLeak << " tokens\n";
    }
}

bool LeakyBucket::addRequest(){
    leakTokens();
    if(currentBucket < maxBucketSize){
        currentBucket++;
        cout<< "request added\n";
        return true;
    }
    cout<<" bucket Full\n";
    return false;
}
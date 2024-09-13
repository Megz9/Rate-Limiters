#include <iostream>
#include "TokenBucket.h"
#include "LeakyBucket.h"
#include "FixedWindowCounter.h"
using namespace std;
int main() {
    cout << "Token Bucket Algorithm demo" << endl;
    TokenBucket t1;
    t1.requestToken();
    t1.requestToken();
    t1.requestToken();
    t1.requestToken();
    t1.requestToken();

    t1.requestToken(); //no tokens available
    sleep_for(milliseconds(11));
    t1.requestToken();

    //////////////////////////////////////////
    cout << "\n\nLeaky Bucket Algorithm Demo\n";
    LeakyBucket bucket(1, 5);//leak a token every 0.5 second

    bucket.addRequest();
    bucket.addRequest();
    bucket.addRequest();

    sleep_for(seconds (3));
    bucket.addRequest();

    sleep_for(milliseconds (2));
    bucket.addRequest();
    bucket.addRequest();
    bucket.addRequest();
    bucket.addRequest(); // This should be dropped as the bucket will likely be full

    //////////////////////////////////////////
    cout << "\n\nFixed Window Algorithm Demo\n";
    FixedWindowCounter fc(5,3); // allow 5 requests every 3 sec
    fc.allowRequest();
    fc.allowRequest();
    fc.allowRequest();
    fc.allowRequest();
    sleep_for(seconds(1));
    fc.allowRequest();
    fc.allowRequest();

    sleep_for(seconds(5));
    fc.allowRequest();
    fc.allowRequest();
    return 0;
}

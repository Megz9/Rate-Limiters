#include <iostream>
#include "TokenBucket.h"
#include "LeakyBucket.h"

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

    return 0;
}

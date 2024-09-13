#include <iostream>
#include "TokenBucket.h"
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
    return 0;
}

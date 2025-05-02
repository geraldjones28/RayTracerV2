#include <iostream>
#include "mytuple.h"

using namespace std;

int main() {
    const MyTuple v1(-1,-2,-3,0);
    const MyTuple v2(1,-2,3,0);

    float mag = magnitude(v1);
    cout << mag << endl;

    return 0;
}
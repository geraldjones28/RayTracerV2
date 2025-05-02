#include <iostream>
#include "mytuple.h"

using namespace std;

int main() {
    const MyTuple v1(1,2,3);
    const MyTuple v2(1,-2,3);

    MyTuple normal = normalize(v1);
    float mag = magnitude(normal);
    normal.print();
    cout << mag << endl;

    return 0;
}
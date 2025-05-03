#include <iostream>
#include "mytuple.h"

using namespace std;

int main() {
    const MyTuple v1(1,2,3);
    const MyTuple v2(2,3,4);

    MyTuple test = cross(v1, v2);
    MyTuple test2 = cross(v2, v1);
    test.print();
    test2.print();

    return 0;
}
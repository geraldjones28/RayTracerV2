#include <iostream>
#include "mytuple.h"

using namespace std;

int main() {
    const MyTuple zv(0,0,0,0);
    const MyTuple v1(1,-2,3,0);

    // Negate Test Case
    const MyTuple test = -v1;
    test.print();

    // Subtraction Test Case
    /*
    const MyTuple test = zv - v1;
    test.print();
    */

    // Addition Test Case
    /*
    const MyTuple test = p + v;
    test.print();
    */

    // Equal Test Case
    /*
    if (p == v) {
        cout << "They are equal!" << endl;
    } else {
        cout << "They are NOT equal!" << endl;
    }
    */

    return 0;
}
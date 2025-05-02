#include <iostream>
#include "mytuple.h"

using namespace std;

int main() {
    const MyTuple p(3, -2, 5, 1);
    const MyTuple v(-2, 3, 1, 0);



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
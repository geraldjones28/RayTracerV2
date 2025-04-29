#include <iostream>
#include "mytuple.h"

using namespace std;

int main() {
    MyTuple p(4.3, -4.2, 3.1, 1.0);
    MyTuple v(4.3, -4.2, 3.1, 0.0);
    if (equal(p, v)) {
        cout << "They are equal!" << endl;
    } else {
        cout << "They are NOT equal!" << endl;
    }

    return 0;
}
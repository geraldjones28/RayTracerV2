//
// Created by Gerald Jones on 4/28/25.
//

#ifndef TUPLE_H
#define TUPLE_H

#include <iostream>

using namespace std;

class mytuple {
  public:
    // An fixed array to store components of tuple
    float e[4];

    // Default Constructor
    mytuple() {}

    // Constructor storing components (x,y,z,w) into e
    mytuple(const float x, const float y, const float z, const float w) {
        e[0] = x; e[1] = y; e[2] = z; e[3] = w;
    }

    inline float x() const { return e[0]; }
    inline float y() const { return e[1]; }
    inline float z() const { return e[2]; }
    inline float w() const { return e[3]; }

    void print() const {
        cout << "(" << x() << ", " << y() << ", " << z() << ", " << w() << ")\n";
    }

};

#endif //TUPLE_H

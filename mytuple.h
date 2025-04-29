//
// Created by Gerald Jones on 4/28/25.
//

#ifndef MYTUPLE_H
#define MYTUPLE_H

#include <iostream>
#include <cmath>

using namespace std;

// My custom tuple class that stores a 'w' value.
// 'w' = 1 means it's a point.
// 'w' = 0 means it's a vector.
class MyTuple {
  public:
    // An fixed array to store components of tuple
    float e[4];

    // Default Constructor
    MyTuple() {}

    // Constructor storing components (x,y,z,w) into e
    MyTuple(const float x, const float y, const float z, const float w) {
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

// A function to test whether two tuples are equal to each other based on an EPSILON
inline const float EPSILON = 1e-5f;
inline bool equal(const MyTuple& a, const MyTuple& b) {
    return ((fabs(a.x() - b.x()) < EPSILON) &&
            (fabs(a.y() - b.y()) < EPSILON) &&
            (fabs(a.z() - b.z()) < EPSILON));
}

#endif //MYTUPLE_H

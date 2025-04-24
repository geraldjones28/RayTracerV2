//
// Created by Gerald Jones on 4/24/25.
//

#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class point {
  public:
    point() {} // Default constructor

    point(const float x, const float y, const float z) {
      e[0] = x; e[1] = y; e[2] = z; e[3] = 1;
    }

    float e[4];
    inline float x() const { return e[0]; }
    inline float y() const { return e[1]; }
    inline float z() const { return e[2]; }
    inline float w() const { return e[3]; }

    void print() const {
      std::cout << "(" << x() << ", " << y() << ", " << z() << ", " << w() << ")\n";
    }
};

#endif //POINT_H

//
// Created by Gerald Jones on 4/28/25.
//

#ifndef MYTUPLE_H
#define MYTUPLE_H

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

// My custom tuple class that stores a 'w' value.
// 'w' = 1 means it's a point.
// 'w' = 0 means it's a vector.
class MyTuple {
  public:
    // A fixed array to store components of tuple
    float e[4];

    // Default Constructor
    MyTuple() = default;

    // Constructor storing components (x,y,z,w) into e
    MyTuple(const float x, const float y, const float z, const float w) {
        e[0] = x; e[1] = y; e[2] = z; e[3] = w;
    }

    // Constructor to create a vector, not needing to provide the w component
    MyTuple(const float x, const float y, const float z) {
        e[0] = x; e[1] = y; e[2] = z; e[3] = 0.0f;
    }

    // Getter functions to call the components of the tuple easily
    inline float x() const { return e[0]; }
    inline float y() const { return e[1]; }
    inline float z() const { return e[2]; }
    inline float w() const { return e[3]; }

    // Function to print out all components of tuple
    void print() const {
        cout << "(" << x() << ", " << y() << ", " << z() << ", " << w() << ")\n";
    }
};

// Function to test whether two tuples are equal to each other based on an EPSILON
inline constexpr float EPSILON = 1e-5f;
inline bool operator==(const MyTuple& a, const MyTuple& b) {
    return ((fabs(a.x() - b.x()) < EPSILON) &&
            (fabs(a.y() - b.y()) < EPSILON) &&
            (fabs(a.z() - b.z()) < EPSILON));
}
// Function to test whether two tuples are equal to each other based on the == overloaded operator
inline bool operator!=(const MyTuple& a, const MyTuple& b) {
    return !(a == b);
}

// Function to add two tuples together. Cannot add two points.
inline MyTuple operator+(const MyTuple& a, const MyTuple& b) {
    if (a.w() == 1 && b.w() == 1) {
        throw logic_error("Cannot add two points.");
    }

    return {a.x() + b.x(),
               a.y() + b.y(),
               a.z() + b.z(),
               a.w() + b.w()};
}

// Function to subtract two tuples together
inline MyTuple operator-(const MyTuple& a, const MyTuple& b) {
    return {a.x() - b.x(),
               a.y() - b.y(),
               a.z() - b.z(),
               a.w() - b.w()};
}

// Function to negate a tuple
inline MyTuple operator-(const MyTuple& a) {
    return {-a.x(),
               -a.y(),
               -a.z(),
               -a.w()};
}

// Function to perform scalar multiplication on a vector
inline MyTuple operator*(const MyTuple& a, float s) {
    if (a.w() == 1) {
        throw logic_error("You should not scale a point (w = 1)");
    }

    return {
        a.x() * s,
        a.y() * s,
        a.y() * s,
        0.0f // preserve vector
    };
}

// Function to perform scalar division on a vector
inline MyTuple operator/(const MyTuple& a, float s) {
    if (a.w() == 1) {
        throw logic_error("You should not scale a point (w = 1)");
    }

    return {
            a.x() / s,
            a.y() / s,
            a.z() / s,
              0.0f // preserve vector
    };
}

// Helper Function to square a float
inline float sqrd (float a) {
    return a*a;
}
// Function to compute the magnitude of a vector
inline float magnitude(const MyTuple& a) {
    if (a.w() == 1) {
        throw logic_error("Magnitude is normally defined for vectors, not points.");
    }

    return (sqrt(sqrd(a.x()) + sqrd(a.y()) + sqrd(a.z())));
}

// Function to normalize a vector
inline MyTuple normalize(const MyTuple& a) {
    if (a.w() == 1) {
        throw logic_error("Cannot normalize a point.");
    }

    return {
            a.x() / magnitude(a),
            a.y() / magnitude(a),
            a.z() / magnitude(a),
           0.0f
    };
}


#endif //MYTUPLE_H

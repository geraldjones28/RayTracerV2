//
// Created by Gerald Jones on 5/3/25.
//

#ifndef COLOR_H
#define COLOR_H

#include <iostream>

using namespace std;

class Color {
  public:
    // An array to store the color components R,G,B
    float c[3];

    // Constructor to create a color
    Color(const float red, const float green, const float blue) {
      c[0] = red; c[1] = green; c[2] = blue;
    }

    inline float red() const { return c[0]; }
    inline float green() const { return c[1]; }
    inline float blue() const { return c[2]; }

    // Function to print out all components of color
    void print() const {
      cout << "Red: " << red() << "\nGreen: " << green() << "\nBlue: " << blue() << "\n";
    }

};

// Function to add two colors together
inline Color operator+(const Color& a, const Color& b) {

  return {a.red() + b.red(),
             a.green() + b.green(),
             a.blue() + b.blue(),
             };
}

// Function to subtract two colors from each other
inline Color operator-(const Color& a, const Color& b) {

  return {a.red() - b.red(),
             a.green() - b.green(),
             a.blue() - b.blue(),
             };
}

// Function to perform scalar multiplication on a color
inline Color operator*(const Color& a, const float s) {

  return {
    a.red() * s,
    a.green() * s,
    a.blue() * s,
  };
}

// Hadamard product to multiply the corresponding colors of two vectors and form (blend) a new color.
inline Color operator*(const Color& a, const Color& b) {
  return {
          a.red() * b.red(),
          a.green() * b.green(),
          a.blue() * b.blue()
  };
}

#endif //COLOR_H

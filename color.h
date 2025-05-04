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
      cout << "(Red:" << red() << ", Green:" << green() << ", Blue:" << blue() << ")\n";
    }

};

#endif //COLOR_H

//
// Created by Gerald Jones on 5/3/25.
//

#include <iostream>
#include "color.h"

using namespace std;

class Canvas {
  public:
    // Fixed array containing the width and height of canvas
    float e[2];

    Color fillColor;

    // Default color constructor
    Canvas(float w, float h)
        : fillColor(Color(0.0f, 0.0f, 0.0f)) {
        e[0] = w;
        e[1] = h;
    }

    inline float w() const { return e[0]; }
    inline float h() const { return e[1]; }
    inline Color color() const { return fillColor; }

    // Function to print out all components of Canvas
    void print() const {
        cout << "width: " << w() << "\nheight: " << h() << "\ncolor: " << fillColor.red() << ", " << fillColor.green() << ", " << fillColor.blue() << "\n";
    }

};


#ifndef CANVAS_H
#define CANVAS_H

#endif //CANVAS_H

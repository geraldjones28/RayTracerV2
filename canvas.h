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

    // A Color object storing the color of the canvas
    Color fillColor;

    // Default color constructor
    Canvas(float w, float h)
        : fillColor(Color(0.0f, 0.0f, 0.0f)) { // Initializing screen color to black
        e[0] = w;
        e[1] = h;
    }

    inline float w() const { return e[0]; }
    inline float h() const { return e[1]; }
    inline Color color() const { return fillColor; }

    // Function to print out all components of Canvas
    void print() const {
        cout << "width: " << w() << "\nheight: " << h() << "\nscreen-color: R: " << fillColor.red() << " | G: " << fillColor.green() << " | B: " << fillColor.blue() << "\n";
    }

};


#ifndef CANVAS_H
#define CANVAS_H

#endif //CANVAS_H

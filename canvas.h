//
// Created by Gerald Jones on 5/3/25.
//

#include <iostream>
#include "color.h"

using namespace std;

class Canvas {
  public:
    // Fixed array containing the width and height of canvas
    size_t e[2];

    // A vector to store a color at a pixel
    vector<Color> pixels;

    // A Color object storing the color of the canvas
    Color fillColor;

    // Default color constructor
    Canvas(const size_t width, const size_t height)
        : fillColor(Color(0, 0, 0)) { // Initializing screen color to black
        e[0] = width;
        e[1] = height;
        // Resizes pixels vector to hold width*height elements, each initialized to fillColor
        pixels.resize((width * height), fillColor);
    }

    size_t width() const { return (e[0]); }
    size_t height() const { return (e[1]); }
    inline Color color() const { return fillColor; }

    // Function to print out all components of Canvas
    void print() const {
        cout << "width: " << width() << "\nheight: " << height() << "\nscreen-color: " << fillColor.red() << " | G: " << fillColor.green() << " | B: " << fillColor.blue() << "\n";
    }
};

inline void write_pixel(Canvas& c, const size_t x, const size_t y, const Color& color) {
    if (x < c.width() && y < c.height()) {
        // This converts (x, y) coordinates into a 1D index inside the canvas’s pixel buffer:
        c.pixels[y * c.width() + x] = color;
    }
}
// Returns the color at the specified pixel in the canvas
inline Color pixel_at(const Canvas& c, const size_t x, const size_t y) {
    if (x < c.width() && y < c.height()) {
        return c.pixels[y * c.width() + x];
    }
    return c.fillColor;
}


#ifndef CANVAS_H
#define CANVAS_H

#endif //CANVAS_H

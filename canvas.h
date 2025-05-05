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
    // Gets the pixel location
    size_t const pixelLocation = y * c.width() + x;

    if (x < c.width() && y < c.height()) {
        // This converts (x, y) coordinates into a 1D index inside the canvas’s pixel buffer:
        c.pixels[pixelLocation] = color;
    }
}
// Returns the color at the specified pixel in the canvas
inline Color pixel_at(const Canvas& c, const size_t x, const size_t y) {
    size_t const pixelLocation = y * c.width() + x;

    if (x < c.width() && y < c.height()) {
        return c.pixels[pixelLocation];
    }
    return c.fillColor;
}

// A function that turns my canvas into a PPM file
inline void canvas_to_ppm(const Canvas& c) {
    cout << "P3\n" <<
            c.width() << " " << c.height() << "\n" <<
            "255\n";

    cout << "\n";

    // Looping thorough pixels in canvas, left to right, top to bottom
    for (size_t y = 0; y < c.height(); ++y) {
        for (size_t x = 0; x < c.width(); ++x) {
            size_t const pixelLocation = y * c.width() + x;

            Color pixel = c.pixels[pixelLocation];

            // Clamp to [0, 1] and convert to 0-255
            int r = static_cast<int>(round(clamp(pixel.red(), 0.0f, 1.0f) * 255));
            int g = static_cast<int>(round(clamp(pixel.green(), 0.0f, 1.0f) * 255));
            int b = static_cast<int>(round(clamp(pixel.blue(), 0.0f, 1.0f) * 255));

            cout << r << ' ' << g << ' ' << b << ' ';
        }
        cout << endl;
    }
}


#ifndef CANVAS_H
#define CANVAS_H

#endif //CANVAS_H

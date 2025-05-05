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

// A Function that writes to a specified pixel in canvas a color [0-based]
inline void write_pixel(Canvas& c, size_t const x, size_t const y, const Color& color) {
    if (x >= c.width() || y >= c.height()) {
        cout << "write_pixel: (" << x << ", " << y << ") is out of bounds for canvas ["
             << c.width() << " x " << c.height() << "]\n";
        return;
    }

    size_t const pixelLocation = y * c.width() + x;
    c.pixels[pixelLocation] = color;
}

// A function that returns the color of the pixel in canvas [0-based]
inline Color pixel_at(const Canvas& c, size_t const x, size_t const y) {
    if (x >= c.width() || y >= c.height()) {
        cout << "pixel_at: (" << x << ", " << y << ") is out of bounds for canvas ["
             << c.width() << " x " << c.height() << "]\n";

        return c.fillColor;  // fallback color
    }

    size_t const pixelLocation = y * c.width() + x;
    return c.pixels[pixelLocation];
}

// A function that turns my canvas into a PPM file
inline void canvas_to_ppm(const Canvas& c) {
    cout << "P3\n" <<
            c.width() << " " << c.height() << "\n" <<
            "255\n";

    cout << "\n";

    // Looping thorough pixels in canvas, left to right, top to bottom [0-based]
    for (size_t y = 0; y < c.height(); ++y) {
        for (size_t x = 0; x < c.width(); ++x) {
            size_t const pixelLocation = y * c.width() + x;

            // Get the current pixel to dissect for color
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

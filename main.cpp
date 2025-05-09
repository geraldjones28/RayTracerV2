#include <iostream>
#include "mytuple.h"
#include "color.h"
#include "canvas.h"

using namespace std;

// Small case test of 'firing projectiles' based on gravity and wind conditions. Using vectors/points
struct Projectile {
    MyTuple position; //Point
    MyTuple velocity; //Vector

    Projectile(const MyTuple& pos, const MyTuple& vel)
        : position(pos), velocity(vel) {}

    inline float xCoord() const { return position.x(); };
    inline float yCoord() const { return position.y(); };
};
struct Environment {
    MyTuple gravity; // Vector
    MyTuple wind; // Vector

    Environment(const MyTuple& grav, const MyTuple& wind)
        : gravity(grav), wind(wind) {}
};

// Tick Function to determine how long it takes for and where a projectile lands
Projectile tick(const Environment& env, const Projectile& proj) {
    return {
            proj.position + proj.velocity,
            proj.velocity + env.gravity + env.wind
            };
}


int main() {

    Canvas c = {900, 550};
    Color red = {1.5, 0, 0}; // Clamped to Pure Red (255)

    // Projectile Launcher
    MyTuple start = {0,1,0, 1}; // Starts one unit above the ground
    MyTuple vector = {1,1.8,0}; // 45º upward and to the right
    MyTuple velocity = normalize(vector) * 11.25;
    Projectile p = {start, velocity};

    MyTuple eGrav = {0,-0.1,0}; // Pulls down
    MyTuple eWind = {-0.01, 0, 0}; // Pushes left
    Environment e = {eGrav, eWind};

    int totalTicks = 0;

    while (p.position.y() >= 0) {
        p = tick(e, p);
        totalTicks++;

        int xCoord = static_cast<int>(p.position.x());
        int yCoord = static_cast<int>(c.height()-p.position.y());

        if (xCoord >= 0 && xCoord < c.width() && yCoord >= 0 && yCoord < c.height()) {
            write_pixel(c, xCoord, yCoord, red);
            // cout << xCoord << ' ' << yCoord;
        }

        // p.position.print();
    };
    // cout << "Total ticks: " << totalTicks << endl;

    canvas_to_ppm(c);

    return 0;
}
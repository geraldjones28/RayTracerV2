#include <iostream>
#include "mytuple.h"
#include "color.h"
#include "canvas.h"

using namespace std;

// Small case test of 'firing projectiles' based on gravity and wind conditions. Using vectors/points
/*
struct Projectile {
    MyTuple position; //Point
    MyTuple velocity; //Vector

    Projectile(const MyTuple& pos, const MyTuple& vel)
        : position(pos), velocity(vel) {}
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
*/

int main() {

    Canvas c = {5, 3};
    Color c1 = {1.5, 0, 0}; // Clamped to Pure Red (255)
    Color c2 = {0, 0.5, 0}; // Clamped to Medium-Dark Green (128)
    Color c3 = {-0.5, 0, 1}; // Clamped to Pure Blue (255)

    write_pixel(c, 0, 0, c1);
    write_pixel(c, 2, 1, c2);
    write_pixel(c, 4, 2, c3);

    canvas_to_ppm(c);

    // Projectile Launcher
    /*
    MyTuple point = {0,1,0, 1}; // Starts one unit above the ground
    MyTuple vector = {1,1,0}; // 45º upward and to the right
    Projectile p = {point, normalize(vector)};

    MyTuple eGrav = {0,-0.1,0}; // Pulls down
    MyTuple eWind = {0.01, 0, 0}; // Pushes right
    Environment e = {eGrav, eWind};

    int totalTicks = 0;

    while (p.position.y() >= 0) {
        p = tick(e, p);
        totalTicks++;
        p.position.print();
    };
    cout << "Total ticks: " << totalTicks << endl;
    */

    return 0;
}
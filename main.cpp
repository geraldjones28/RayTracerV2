#include <iostream>
#include "mytuple.h"

using namespace std;

// Small case test of 'firing projectiles' based on gravity and wind conditions. Using vectors/points
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

int main() {
    MyTuple point = {0,1,0, 1}; // Starts one unit above the ground
    MyTuple vector = {1,1,0}; // 45º upward and to the right
    Projectile p = {point, normalize(vector)};

    MyTuple eGrav = {0,-0.1,0}; // Pulls down
    MyTuple eWind = {0.01, 0, 0}; // Pushes right
    Environment e = {eGrav, eWind};

    while (p.position.y() >= 0) {
        p = tick(e, p);
        p.position.print();
    };

    return 0;
}
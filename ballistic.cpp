//
// Created by Ole Donnermeyer on 22.04.24.
//

#include "ballistic.h"

#include <complex>


Ballistic::Ballistic(const string &Id, const float takeOff, const float landing) : Ufo(Id) {

    if ((takeOff <= 0 ) || (takeOff > 90)) {
        takeOffAngle = 45;
    } else {
        takeOffAngle = takeOff;
    }

    if ((landing <= 0 ) || (landing > 90)) {
        landingAngle = 45;
    } else {
        landingAngle = landing;
    }
}

Ballistic::~Ballistic() = default;

float Ballistic::getTakeOffAngle() const {
    return takeOffAngle;
}


float Ballistic::getLandingAngle() const {
    return landingAngle;
}

vector<float> Ballistic::firstWaypoint(const float x, const float y, const float height) const {


    float dx = x - sim->getX();
    float dy = y - sim->getY();

    float rad = takeOffAngle * M_PI / 180;
    float t = height / tan(rad);
    float norm = sqrt(pow(dx, 2) + pow(dy, 2));

    float perc = t  / norm;


    vector<float> vec = { ( dx * perc) + sim->getX(),( dy * perc) + sim->getY()};


    return vec;
}

  vector<float> Ballistic::secondWaypoint(const float x, const float y, const float height) const {


    // calc top part of triangle
    float a = height / tan(landingAngle * M_PI / 180);

    vector<float> first_w = firstWaypoint(x, y, height);


    // calc vector to second waypoint
    // bottom to bottom (only dir)
    float v_d_x = x - first_w[0];
    float v_d_y = y - first_w[1];

    float len = sqrt(pow(v_d_x, 2) + pow(v_d_y, 2));

    //normalize vector
    float n_v_d_x = v_d_x / len;
    float n_v_d_y = v_d_y / len;

    float multiplier = len - a;

    float x2 = first_w[0] + (n_v_d_x * multiplier);
    float y2 = first_w[1] + (n_v_d_y * multiplier);


    return {x2,y2};
}


void Ballistic::flyToDest(const float x, const float y, const float height, const int speed) const {
    vector<float> vec1 = firstWaypoint(x, y, height);
    vector<float> vec2 = secondWaypoint(x, y, height);

    //locate first waypoint
    sim->flyTo(vec1[0], vec1[1], height, speed, speed);

    //onto second
    sim->flyTo(vec2[0], vec2[1], height, speed, speed); // vpost = speed => dont stop after reaching point

    //fly to target point
    sim->flyTo(x, y, 0, speed, 0);
}
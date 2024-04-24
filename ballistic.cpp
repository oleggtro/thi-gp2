//
// Created by Ole Donnermeyer on 22.04.24.
//

#include "ballistic.h"

#include <complex>
#include <iostream>


Ballistic::Ballistic(const string &Id, float takeOff,  float landing) : Ufo(Id) {

    if ((takeOff <= 0 ) || (takeOff > 90)) {
        takeOff = 45;
    }

    if ((landing <= 0 ) || (landing > 90)) {
        landing = 45;
    }

    takeOffAngle = takeOff;
    landingAngle = landing;
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

    cout << "vec: " << vec[0] << " " << vec[1] << endl;

    return vec;
}

  vector<float> Ballistic::secondWaypoint(const float x, const float y, const float height) const {


    // calc top part of triangle
    float a = height / tan(landingAngle * M_PI / 180);

    vector<float> first_w = firstWaypoint(x, y, height);


    float v_d_x = x - first_w[0];
    float v_d_y = y - first_w[1];

    float len = sqrt(pow(v_d_x, 2) + pow(v_d_y, 2));

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
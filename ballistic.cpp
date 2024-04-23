//
// Created by Ole Donnermeyer on 22.04.24.
//

#include "ballistic.h"

#include <complex>


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
    float t = height / tan(takeOffAngle);

    float dx = x - sim->getX();
    float dy = y - sim->getY();


    float norm = sqrt(pow(dx, 2) + pow(dy, 2));

    float ndx = dx / norm;
    float ndy = dy / norm;



    return {sim->getX() + (ndx * t),sim->getY() + (ndy * t), height};
}

  vector<float> Ballistic::secondWaypoint(const float x, const float y, const float height) const {
    float t = height / tan(landingAngle);

    float dx = x - sim->getX();
    float dy = y - sim->getY();


    float norm = sqrt(pow(dx, 2) + pow(dy, 2));

    float ndx = dx / norm;
    float ndy = dy / norm;

    return {sim->getX() - (ndx * t),sim->getY() - (ndy * t), height};
}





void Ballistic::flyToDest(const float x, const float y, const float height, const int speed) const {
    vector<float> vec = {};
    //locate first waypoint
    vec = firstWaypoint(x, y, height);
    sim->flyTo(vec[0], vec[1], vec[2], speed, speed);

    //onto second
    vec = secondWaypoint(x, y, height);
    sim->flyTo(vec[0], vec[1], vec[2], speed, speed); // vpost = speed => dont stop after reaching point

    //fly to target point
    sim->flyTo(x, y, height, speed, speed);

}
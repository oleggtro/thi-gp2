//
// Created by Ole Donnermeyer on 22.04.24.
//

#include "ballistic.h"


Ballistic::Ballistic(float takeOff, float landing) {
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

float Ballistic::getLandingAngle() const {
    return landingAngle;
}

float Ballistic::getTakeOffAngle() const {
    return takeOffAngle;
}



//
// Created by Ole Donnermeyer on 19.04.24.
//

#include "ufo.h"
#include "ufosim.h"
#include <cmath>


Ufo::Ufo(const string &pId) {
    Ufosim::setSpeedup(4);
    sim = new Ufosim();
    id = pId;
}

Ufo::~Ufo() {
    delete sim;
}


const string & Ufo::getId() const {
    return id;
}

vector<float> Ufo::getPosition() const {
    return {sim->getX(), sim->getY(), sim->getZ()};
}

float Ufo::getFtime() const {
    return sim->getFtime();
}


float Ufo::angle(const float x1, const float y1, const float x2, const float y2) {
    if (x1 == x2 && y1 == y2) {
        return 0.0;
    }

    float dx = x2 - x1;
    float dy = y2 - y1;

    float angleRad = atan2(dy, dx);

    float angleDeg = angleRad * (180.0 / M_PI);

    angleDeg = 90 - angleDeg;
    if (angleDeg < 0) {
        angleDeg += 360;
    }

    return angleDeg;
}




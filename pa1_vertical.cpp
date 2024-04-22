//
// Created by Ole Donnermeyer on 19.04.24.
//

#include "pa1_vertical.h"
#include "ufosim.h"
#include <cmath>

const string Vertical::type = "vertical";

Vertical::Vertical(const string &pId) {
    Ufosim::setSpeedup(4);
    sim = new Ufosim();
    id = pId;
}

Vertical::~Vertical() {
    delete sim;
}

string Vertical::getType() {
    return type;
}

const string & Vertical::getId() const {
    return id;
}

vector<float> Vertical::getPosition() const {
    return {sim->getX(), sim->getY(), sim->getZ()};
}

float Vertical::getFtime() const {
    return sim->getFtime();
}

void Vertical::flyToDest(const float x, const float y, const float height, const int speed) const {
    sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
    sim->flyTo(x, y, height, speed, 0);
    sim->flyTo(x, y, 0, speed, 0);
}


float Vertical::angle(const float x1, const float y1, const float x2, const float y2) {
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
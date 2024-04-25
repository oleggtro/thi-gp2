//
// Created by Ole Donnermeyer on 19.04.24.
//

#include "vertical.h"
#include "ufosim.h"
#include <cmath>
using namespace std;

Vertical::Vertical(const std::string& pId) : Ufo(pId) {}

void Vertical::flyToDest(const float x, const float y, const float height, const int speed) const {
    sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
    sim->flyTo(x, y, height, speed, 0);
    sim->flyTo(x, y, 0, speed, 0);
}

float Vertical::distance(const float x1, const float y1, const float x2, const float y2, const float h) {
    float dx = x2 - x1;
    float dy = y2 - y1;

    float length = sqrt(dx * dx + dy * dy);

    // account for raising up and landing
    length += h * 2;

    return length;
}

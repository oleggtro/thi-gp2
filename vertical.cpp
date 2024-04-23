//
// Created by Ole Donnermeyer on 19.04.24.
//

#include "vertical.h"
#include "ufosim.h"
#include <cmath>
using namespace std;

Vertical::Vertical(const std::string& pId) : Ufo(pId) {
}


void Vertical::flyToDest(const float x, const float y, const float height, const int speed) const {
    sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
    sim->flyTo(x, y, height, speed, 0);
    sim->flyTo(x, y, 0, speed, 0);
}

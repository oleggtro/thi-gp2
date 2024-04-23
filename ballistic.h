//
// Created by Ole Donnermeyer on 22.04.24.
//

#ifndef BALLISTIC_H
#define BALLISTIC_H


#include <vector>

#include "ufo.h"
using namespace std;


class Ballistic : public Ufo {
protected:
    float takeOffAngle;
    float landingAngle;

public:
    Ballistic(const string& id, float takeOff, float landing);
    ~Ballistic();
    float getTakeOffAngle() const;
    float getLandingAngle() const;

    std::vector<float> firstWaypoint(const float x, const float y, const float height) const;
    std::vector<float> secondWaypoint(const float x, const float y, const float height) const;
    void flyToDest(const float x, const float y, const float height, const int speed) const;
};



#endif //BALLISTIC_H

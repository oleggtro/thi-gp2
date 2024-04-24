//
// Created by Ole Donnermeyer on 19.04.24.
//

#include <string>
#include <vector>

#include "ufo.h"
using namespace std;

#ifndef VERTICAL_H
#define VERTICAL_H



class Vertical : public Ufo {

public:

    Vertical(const string& pId);
    ~Vertical() = default;
    void flyToDest(const float x, const float y, const float height, const int speed) const override;
    static float distance(const float x1, const float y1, const float x2, const float y2, const float h);
};



#endif //VERTICAL_H

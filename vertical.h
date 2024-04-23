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
};



#endif //VERTICAL_H

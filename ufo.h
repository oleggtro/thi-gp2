//
// Created by Ole Donnermeyer on 22.04.24.
//


#include <string>
#include <vector>
using namespace std;
#include "ufosim.h"

#ifndef UFO_H
#define UFO_H



class Ufo {
    string id;
    protected:
    Ufosim* sim;


public:
    Ufo(const string& pId);
    virtual ~Ufo();
    static string getType();
    const string& getId() const;

    vector<float> getPosition() const;
    float getFtime() const;
    virtual void flyToDest(const float x, const float y, const float height, const int speed) const;

    static float angle(const float x1, const float y1, const float x2, const float y2);
};




class Vertical : public Ufo {
    Vertical();
    ~Vertical();
    void flyToDest(const float x, const float y, const float height, const int speed) const override;
};





#endif //UFO_H

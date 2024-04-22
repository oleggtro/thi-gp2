//
// Created by Ole Donnermeyer on 22.04.24.
//

#ifndef BALLISTIC_H
#define BALLISTIC_H


class Ballistic {
private:
    float takeOffAngle;
    float landingAngle;

public:
    Ballistic(float takeOff, float landing);
    ~Ballistic();
    float getTakeOffAngle() const;
    float getLandingAngle() const;
};



#endif //BALLISTIC_H

//
// Created by Ole Donnermeyer on 24.04.24.
//

#ifndef ROUTE_H
#define ROUTE_H
#include <vector>

using namespace std;

class Route {
    private:
    vector<pair<float, float>> destinations;
    float height;

    float (*dist)(float x1, float x2, float y1, float y2, float h);


public:
    Route(const float pHeigth, float (*fn_dist)(const float x1, const float x2, const float y1, const float y2, const float h));
    ~Route();

    void add(const float destX, const float destY);
    const vector<pair<float,float>>& getDestinations() const;
    float getHeight() const;
    void setHeight(const float height);
    void setDist(float (*dist)(const float x1, const float x2, const float y1, const float y2, const float h));
    float distance() const;
    void shortestRoute();


};



#endif //ROUTE_H

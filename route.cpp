//
// Created by Ole Donnermeyer on 24.04.24.
//

#include "route.h"
#include <math.h>
#include <algorithm>
#include <limits>


Route::Route(const float pHeigth,
                float(*fn_dist)(const float x1, const float x2, const float y1, const float y2, const float h)) {
    height = pHeigth;
    dist = fn_dist;
    destinations = new vector<pair<float, float>>();
}

Route::~Route() {
    delete destinations;
}

void Route::add(const float destX, const float destY) {
    destinations->emplace_back(destX, destY);
}

const vector<pair<float,float>>& Route::getDestinations() const {
    return *destinations;
}

float Route::getHeight() const {
    return height;
}

void Route::setHeight(const float new_height) {
    height = new_height;
}

void Route::setDist(float(*fn_dist)(const float x1, const float x2, const float y1, const float y2, const float h)) {
    dist = fn_dist;
}


float Route::distance() const {
    float total_dist = 0;

    if (destinations->empty()) {
        return 0;
    }

    // start at 00 and go to first waypoint
    total_dist = dist(0, 0, destinations->front().first, destinations->front().second, height);


    pair<float, float> prev_dest = destinations->front();
    for (auto dest : *destinations) {
        if (dest == prev_dest) continue;
        total_dist += dist(prev_dest.first, prev_dest.second, dest.first, dest.second, height);
        prev_dest = dest;
    }

    //acc for back to start
    total_dist += dist(destinations->back().first, destinations->back().second, 0, 0, height);


    return total_dist;
}


void Route::shortestRoute() {
    if (destinations->empty()) {
        return;
    }

    vector<pair<float, float>> best_route = *destinations;

    std::sort(destinations->begin(), destinations->end());

    //set min distance to max value, so that on first iteration the first route will be the best
    float shortest_route = numeric_limits<float>::max();

    do {
        float t_dist = 0.0;

        // back to start
        t_dist = distance();

        // check of current route is better than previously best route. if yes, overwrite
        if (t_dist < shortest_route) {
            shortest_route = t_dist;
            best_route = *destinations;
        }

    } while (next_permutation(destinations->begin(), destinations->end()));


    *destinations = best_route;
}
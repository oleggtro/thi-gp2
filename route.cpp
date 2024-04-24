//
// Created by Ole Donnermeyer on 24.04.24.
//

#include "route.h"

Route::Route(float pHeigth,
    float(*fn_dist)(const float x1, const float x2, const float y1, const float y2, const float h)) {
    height = pHeigth;
    dist = fn_dist;
}

Route::~Route() {
    destinations.clear();
}

void Route::add(const float destX, const float destY) {
    destinations.emplace_back(destX, destY);
}



const vector<pair<float,float>>& Route::getDestinations() const {
    return destinations;
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
    float len = 0;

    for (auto dest : destinations) {
        len += dist(dest.first, dest.second, dest.first, dest.second, height);
    }
}


void Route::shortestRoute() {
    vector<pair<float, float>> best_route = destinations;
    float min_distance = numeric_limits<float>::max();

    sort(destinations.begin(), destinations.end());

    do {
        float total_distance = 0.0;

        total_distance += dist(0.0, destinations[0].first, 0.0, destinations[0].second, height);

        for (int i = 0; i < destinations.size() - 1; ++i) {
            total_distance += dist(destinations[i].first, destinations[i+1].first, destinations[i].second, destinations[i+1].second, height);
        }

        total_distance += dist(destinations.back().first, 0.0, destinations.back().second, 0.0, height);

        if (total_distance < min_distance) {
            min_distance = total_distance;
            best_route = destinations;
        }
    } while (next_permutation(destinations.begin(), destinations.end()));

    destinations = best_route;
}

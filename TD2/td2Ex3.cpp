#include "Trajectory.hpp"
#include <iostream>

using namespace std;

void Trajectory::print() {

    for (size_t i = 0; i < numberOfPoints; i++)
        points[i].print();
}

Point3D& Trajectory::getPoint(const size_t& n) {

    return points[n];
}

float Trajectory::getTotalDistance() {

    float total = 0;

    for (size_t i = 0; i < numberOfPoints - 1; i++) {

        total += points[i].distanceTo(points[i + 1]);
    }

    return total;
}
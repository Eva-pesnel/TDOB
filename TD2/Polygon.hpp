#pragma once
#include <vector>
#include "Point3D.hpp"

class Polygon {

private:
    std::vector<Point3D> points;

public:

    Polygon(std::vector<Point3D> p);

    float getArea();
};
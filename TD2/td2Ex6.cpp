#include "Polygon.hpp"
#include <cmath>

Polygon::Polygon(std::vector<Point3D> p) {

    points = p;
}

float Polygon::getArea() {

    float area = 0;

    int n = points.size();

    for (int i = 0; i < n; i++) {

        int j = (i + 1) % n;

        area += points[i].getX() * points[j].getY();
        area -= points[j].getX() * points[i].getY();
    }

    return abs(area) / 2;
}

int main() {

    vector<Point3D> triangle = {
        Point3D(0,0,0),
        Point3D(4,0,0),
        Point3D(0,3,0)
    };

    Polygon p(triangle);

    cout << "Area = " << p.getArea() << endl;
}
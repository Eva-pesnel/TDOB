#include "Point3D.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

Point3D::Point3D() {

    x = rand() % 101;
    y = rand() % 101;
    z = rand() % 101;
}

Point3D::Point3D(const float& newx, const float& newy, const float& newz) {

    x = newx;
    y = newy;
    z = newz;
}

void Point3D::setXYZ(const float& newx, const float& newy, const float& newz) {

    x = newx;
    y = newy;
    z = newz;
}

void Point3D::setX(const float& newx) { x = newx; }
void Point3D::setY(const float& newy) { y = newy; }
void Point3D::setZ(const float& newz) { z = newz; }

float Point3D::getX() { return x; }
float Point3D::getY() { return y; }
float Point3D::getZ() { return z; }

void Point3D::print() {

    cout << "(" << x << "," << y << "," << z << ")" << endl;
}

float Point3D::distanceTo(const Point3D& p) {

    float dx = x - p.x;
    float dy = y - p.y;
    float dz = z - p.z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

//Q1: * Passage par référence: 
//             Avantages : pas de copie mémoire, plus rapide, permet modifier variable
//             Inconvénient : peut modifier la variable originale
//    * Passage par référence constante:
//             Avantages : pas de copie, plus rapide, sécurisé(impossible de modifier)
//             Inconvénient: impossible de modifier la variable
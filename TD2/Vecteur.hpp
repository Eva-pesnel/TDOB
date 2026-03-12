#pragma once
class Vecteur {

private:
    float x, y, z;

public:

    Vecteur(Point3D a, Point3D b);

    Vecteur add(const Vecteur& v);

    Vecteur multiply(float k);

    bool equals(const Vecteur& v);
};
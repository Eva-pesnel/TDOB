Vecteur::Vecteur(Point3D a, Point3D b) {

    x = b.getX() - a.getX();
    y = b.getY() - a.getY();
    z = b.getZ() - a.getZ();
}

Vecteur Vecteur::add(const Vecteur& v) {

    Vecteur r = *this;

    r.x += v.x;
    r.y += v.y;
    r.z += v.z;

    return r;
}

Vecteur Vecteur::multiply(float k) {

    Vecteur r = *this;

    r.x *= k;
    r.y *= k;
    r.z *= k;

    return r;
}

bool Vecteur::equals(const Vecteur& v) {

    return (x == v.x && y == v.y && z == v.z);
}
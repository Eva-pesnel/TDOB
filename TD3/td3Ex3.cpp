#pragma once
#include <iostream>
using namespace std;

enum class Color : unsigned char {
    blue, green, orange, brown
};

class Shape {
public:
    Shape(const Color& color) : color_(color), count_(++global_count_) {}

    virtual float get_area() = 0;
    virtual void print_data() = 0;

protected:
    const unsigned count_;
    const Color color_;

private:
    static unsigned global_count_;
};

unsigned Shape::global_count_ = 0;

//RECTANGLE

class Rectangle : public Shape {
public:
    Rectangle(float l, float w, Color c = Color::blue)
        : Shape(c), length_(l), width_(w) {
    }

    float get_area() override {
        return length_ * width_;
    }

    void print_data() override {
        cout << "Rectangle: " << length_ << " x " << width_ << endl;
    }

protected:
    float length_;
    float width_;
};


//TRIANGLE

#include <cmath>

class Triangle : public Shape {
public:
    Triangle(float a, float b, float c, Color col = Color::green)
        : Shape(col), length_side1_(a), length_side2_(b), length_side3_(c) {
    }

    float get_area() override {
        float d = (length_side1_ + length_side2_ + length_side3_) / 2;
        return sqrt(d * (d - length_side1_) * (d - length_side2_) * (d - length_side3_));
    }

    void print_data() override {
        cout << "Triangle: "
            << length_side1_ << " "
            << length_side2_ << " "
            << length_side3_ << endl;
    }

private:
    float length_side1_, length_side2_, length_side3_;
};

//CERCLE

class Circle : public Shape {
public:
    Circle(float r, Color c = Color::orange)
        : Shape(c), radius_(r) {
    }

    float get_area() override {
        return 3.14159f * radius_ * radius_;
    }

    void print_data() override {
        cout << "Circle radius: " << radius_ << endl;
    }

private:
    float radius_;
};

//POINTS 2D ET 3D

class Point2D {
protected:
    float x, y;

public:
    Point2D(float px = 0, float py = 0) : x(px), y(py) {}
};

class Point3D : public Point2D {
private:
    float z;

public:
    Point3D(float px, float py, float pz)
        : Point2D(px, py), z(pz) {
    }
};
#include <iostream>
using namespace std;

class TextRectangle {

private:
	int height = 7;
	int width = 3;   // private attributes

public:

	// Setters and getters 

	void setHeight(const int& newHeight);
	void setWidth(const int& newWidth);

	int getHeight();
	int getWidth();

	// methods

	int getArea();
	int getPerimeter();


	void print();
	void drawArea(const char& pattern);
	void drawPerimeter(const char& pattern);
};

void TextRectangle::setHeight(const int& newHeight) {
	height = newHeight;
}

void TextRectangle::setWidth(const int& newWidth) {
	width = newWidth;
}

int TextRectangle::getHeight() {
	return height;
}

int TextRectangle::getWidth() {
	return width;
}

int TextRectangle::getArea() {
	return height * width;
}

int TextRectangle::getPerimeter() {
	return 2 * (height + width);
}

void TextRectangle::print() {
	cout << "Height :" << height << endl;
	cout << "Width :" << width << endl;
	cout << "Area :" << getArea() << endl;
	cout << "Perimeter :" << getPerimeter() << endl;
}

void TextRectangle::drawArea(const char& pattern) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << pattern;
		}
		cout << endl;
	}
}

void TextRectangle::drawPerimeter(const char& pattern) {

	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {

			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				cout << pattern;
			else
				cout << " ";
		}

		cout << endl;
	}
}

int main() {

	TextRectangle r;

	r.print();

	cout << endl;

	r.drawArea('*');

	cout << endl;

	r.drawPerimeter('*');

	return 0;
}


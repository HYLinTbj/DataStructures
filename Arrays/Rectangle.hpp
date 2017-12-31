#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle {
public:
	Rectangle(int, int, int, int);
	~Rectangle();
	int GetHeight();
	int GetWidth();
	bool operator==(const Rectangle&);
private:
	int x_low_, y_low_, height_, width_;
};

#endif
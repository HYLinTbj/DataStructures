#include "Rectangle.hpp"

Rectangle::Rectangle(int x = 0, int y = 0, int h = 0, int w = 0)
: x_low_(x), y_low_(y), height_(h), width_(w)
{}
Rectangle::~Rectangle() {}

int Rectangle::GetHeight() { return height_; }
int Rectangle::GetWidth() { return width_; }

bool Rectangle::operator==(const Rectangle& s) {
	return this == &s ||
		x_low_ == s.x_low_ && y_low_ == s.y_low_ &&
		height_ == s.height_ && width_ == s.width_;
}

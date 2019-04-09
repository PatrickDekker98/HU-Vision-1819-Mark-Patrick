#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) :
	RGBImage(other.getWidth(), other.getHeight()) {
	std::copy(other.data.begin(), other.data.end(), data.begin());
	size = other.getWidth() * other.getHeight();
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	size = width * height;
	data.resize(size);
}

RGBImageStudent::~RGBImageStudent() {
	data.clear();
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	size = width * height;
	data.resize(size);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	size = getWidth() * getHeight();
	data.resize(size);
	std::copy(other.data.begin(), other.data.end(), data.begin());
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	unsigned int index = getHeight() * x + y;
	if (index <= size) {
		data[index] = new RGB(pixel);
	}
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	if (i <= size) {
		data[i] = new RGB(pixel);
	}
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	unsigned int index = getHeight() * x + y;
	if (index <= size) {
		return *data[index];
	}
	return 0;
}

RGB RGBImageStudent::getPixel(int i) const {
	if (i < size) {
		return *data[i];
	}
	return 0;
}
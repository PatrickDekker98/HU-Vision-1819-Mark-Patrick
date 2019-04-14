#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) :
	RGBImage(other.getWidth(), other.getHeight()) {
	data.resize(other.data.size());
	std::copy(other.data.begin(), other.data.end(), data.begin());
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	data.resize(width * height);
}

RGBImageStudent::~RGBImageStudent() {
	data.clear();
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	data.resize(width * height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	
	data.resize(other.data.size());
	std::copy(other.data.begin(), other.data.end(), data.begin());
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	unsigned int index = getHeight() * x + y;
	if (index <= data.size()) {
//		data[index] = new RGB(pixel);
		data[index] = pixel;
	}
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	if (i <= getWidth() * getHeight()) {
		//data[i] = new RGB(pixel);
		data[i] = pixel;
	}
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	unsigned int index = getHeight() * x + y;
	//unsigned int index = getWidth() * y + x;
	if (index <=data.size()) {
		return data[index];
	}
	return 0;
}

RGB RGBImageStudent::getPixel(int i) const {
	if (i < data.size()) {
		return data[i];
	}
	return 0;
}
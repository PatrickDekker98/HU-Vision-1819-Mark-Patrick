#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	size = getWidth() * getHeight();
	data.resize(size);
	std::copy(other.data.begin(), other.data.end(), data.begin());
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	size = height * width;
	data.resize(size);
}

IntensityImageStudent::~IntensityImageStudent() {
	data.clear();
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	size = width * height;
	data.resize(size);

}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	data.resize(other.data.size());
	std::copy(other.data.begin(), other.data.end(), data.begin());
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	int index = getHeight()*x + y;
	if (index <= size) {
		data[index] = pixel;
	}
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	if (i <= size) {
		data[i] = pixel;
	}
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	int index = getHeight() * x + y;
	if (index <= size) {
		return data[index];

	}
	return 0;
}

Intensity IntensityImageStudent::getPixel(int i) const {
	if (i <= size) {
		return data[i];

	}
	return 0;
}
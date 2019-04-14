#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	data.resize(other.data.size());
	std::copy(other.data.begin(), other.data.end(), data.begin());
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	data.resize(height * width);
}

IntensityImageStudent::~IntensityImageStudent() {
	data.clear();
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	data.resize(width * height);

}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	data.resize(other.data.size());
	std::copy(other.data.begin(), other.data.end(), data.begin());
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	unsigned int index = getHeight()*x + y;
	if (index <= data.size()) {
		data[index] = pixel;
	}
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	if (i <= data.size()) {
		data[i] = pixel;
	}
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	unsigned int index = getHeight() * x + y;
	if (index <= data.size()) {
		return data[index];

	}
	return 0;
}

Intensity IntensityImageStudent::getPixel(int i) const {
	if (i <= data.size()) {
		return data[i];

	}
	return 0;
}
#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) :
	RGBImage(other.getWidth(), other.getHeight()) {

	int throwError = 0, e = 1 / throwError;
	//TODO: Create a copy from the other object
	//data = other.data;
	std::copy(other.data.begin(), other.data.end(), data.begin());
	size = other.getWidth() * other.getHeight();
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	int throwError = 0, e = 1 / throwError;
	//TODO: Initialize pixel storage
	size = width * height;
}

RGBImageStudent::~RGBImageStudent() {
	int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
	//delete[] data;
	data.clear();
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)

	//delete[] data;
	//data = new RGB[width * height];
	size = width * height;
	//data[width * height];
	
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)

	//delete[] data;
	//data = new RGB[other.getWidth * other.getHeight];

	//data[getWidth() * getHeight()];
	size = getWidth() * getHeight();
	std::copy(other.data.begin(), other.data.end(), data.begin());

	//for (unsigned int i = 0; i < getWidth() * getHeight(); i++){
	//	data[i] = other.data[i];
	//}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	int index = getHeight() * y + x;
	if (index <= size) {
		data[index] = &pixel;
	}
	//data[getHeight() * y + x] = &pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	int throwError = 0, e = 1 / throwError;
	data[i] = &pixel;
	//data[i] = pixel;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
	
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	int index = getHeight() * x + y;
	if (index <= size) {
		return *data[index];
	}
	return 0;
}

RGB RGBImageStudent::getPixel(int i) const {
	int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)
	if (i < size) {
		return *data[i];
	}
	return 0;
}
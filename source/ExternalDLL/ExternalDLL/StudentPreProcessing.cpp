#include "StudentPreProcessing.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImage * intens = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());
	for (unsigned int i = 0; i < image.getHeight() * image.getWidth(); i++) {
		intens->setPixel(i, Intensity(image.getPixel(i).b));
	}
	return intens;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}
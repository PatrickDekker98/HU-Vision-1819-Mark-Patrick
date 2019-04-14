#include "StudentPreProcessing.h"
#include "ImageFactory.h"
//#include <algorithm>
//#include <cstdlib>

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {

	auto * gray_image = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());

	auto total_pixels = image.getHeight() * image.getWidth();

	for (int i = 0; i < total_pixels; i++)
	{
		auto pixel = image.getPixel(i);

		//Averaging
		Intensity Averaging = ((pixel.r + pixel.g + pixel.b) / 3);

		// Luma
		Intensity luma = (pixel.r * 0.3 + pixel.g * 0.59 + pixel.b * 0.11);
	
		// Single color channel (blue)
		Intensity blue = (pixel.b);

		// Single color channel (green)
		Intensity green = (pixel.g);

		// Single color channel (red)
		Intensity red = (pixel.r);

		gray_image->setPixel(i, red);
	}
	return gray_image;
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
#include "StudentPreProcessing.h"
#include "ImageFactory.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {

	auto * gray_image = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());

	auto total_pixels = image.getHeight() * image.getWidth();

	for (int i = 0; i < total_pixels; i++ )
	{
		auto pixel = image.getPixel(i);
		Intensity p = (pixel.r  + pixel.g  + pixel.b / 3);

		gray_image->setPixel(i, p);
		
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
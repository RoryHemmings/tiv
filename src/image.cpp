#include <iostream>
#include "image.h"

Image::Image(Window* window, const std::string& imagePath, int maxWidth, int maxHeight, IMAGE_MODE mode)
	: m_window(window),
		m_mode(mode)
{
	m_img = cv::imread(imagePath, cv::IMREAD_COLOR);	
	if (m_img.data == NULL)
	{
		std::cerr << "Path: " << imagePath << " is invalid." << std::endl;
		exit(1);
	}

	// Get scalars such that the image will fit into the viewport for sure
	double horizontalRatio = m_img.cols / maxWidth;
	double verticalRatio = m_img.rows / maxHeight;
	if (horizontalRatio >= verticalRatio)
		m_widthScale = m_heightScale = 1 / horizontalRatio;
	else
		m_widthScale = m_heightScale = 1 / verticalRatio;
}

void Image::Resize(double widthScale, double heightScale)
{
	
}

/**
 * x: double from 0 to 1, represents percentage of the way through the image horizontally
 * y: double from 0 to 1, represents percentage of the way through the image vertically
 * width: double from 0 to 1, represents width of area being sampled as percentage of image
 * height: double from 0 to 1, represents height of area being sampled as percentage of image
 * color: input color where output color of resulting character is stored
 *
 * returns the resulting character based on mode, scale, and color/intensity of area sampled
 */
char Image::Sample(double x, double y, double width, double height, COLOR& color) const
{

}

int Image::GetWidth() const
{
	return m_widthScale * m_img.cols;	
}

int Image::GetHeight() const
{
	return m_heightScale * m_img.rows;	
}


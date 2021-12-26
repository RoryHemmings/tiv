#include <iostream>
#include "image.h"

const char CHARACTER_SET[] = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$)}]";
const size_t CHARACTER_SET_LEN = 70;

// Returns corresponding character. Note, pixelValue is in BGR form (thanks opencv)
char pixelToCharacter(const cv::Vec3b& pixelValue)
{
	// Intensity conversion using CCIR 601 grayscale weights
	int intensity = pixelValue[2]*0.2989 + pixelValue[1]*0.5870 + pixelValue[0]*0.1140;	
	
	int i = (intensity/256.0) * CHARACTER_SET_LEN;	
	return CHARACTER_SET[i];
}

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
	// Make sure then when resizing, the image has positive dimensions that fit on screen	
}

/**
 * x: double from 0 to 1, represents percentage of the way through the image horizontally
 * y: double from 0 to 1, represents percentage of the way through the image vertically
 * width: double from 0 to 1, represents width of area being sampled as percentage of image
 * height: double from 0 to 1, represents height of area being sampled as percentage of image
 * interpolation: interpolation algorithm to scale the image
 *
 * returns the resulting string to print one character, for one based on current mode, scale,
 * and color/intensity of area sampled
 */
std::string Image::Sample(double x, double y, INTERPOLATION interpolation) const
{
	if (x < 0 || x > 1 || y < 0 || y > 1)
		return "";

	int col = floor(x * (GetWidth()-1));	
	int row = floor(y * (GetHeight()-1));	
	
	cv::Vec3b pixelValue = m_img.at<cv::Vec3b>(row, col);
	char c = pixelToCharacter(pixelValue);

	// TODO implement color
	return "" + c + "";	
}

int Image::GetWidth() const
{
	return m_widthScale * m_img.cols;	
}

int Image::GetHeight() const
{
	return m_heightScale * m_img.rows;	
}


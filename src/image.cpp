#include <iostream>
#include "image.h"

const char CHARACTER_SET[71] = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
const size_t CHARACTER_SET_LEN = 70;

// Returns corresponding character. Note, pixelValue is in BGR form (thanks opencv)
uchar pixelToCharacter(const cv::Vec3b& pixelValue)
{
	// Intensity conversion using CCIR 601 grayscale weights
	int intensity = pixelValue[2]*0.2989 + pixelValue[1]*0.5870 + pixelValue[0]*0.1140;	
	
	int i = (intensity/256.0) * CHARACTER_SET_LEN;	
	return CHARACTER_SET[i];
}

std::string colorCharacter(uchar c, const cv::Vec3b& pixelValue)
{
	std::stringstream ret;		
	ret << "\x1b[38;2;";
	ret << static_cast<int>(pixelValue[2]) << ";";
	ret << static_cast<int>(pixelValue[1]) << ";";
	ret << static_cast<int>(pixelValue[0]) << "m";
	ret << c;
	ret << "\x1b[0m"; 

	return ret.str();
}

Image::Image(Window* window, const std::string& imagePath, int maxWidth, int maxHeight, IMAGE_MODE mode, INTERPOLATION interpolation)
	: m_window(window),
		m_mode(mode),
		m_interpolation(interpolation)
{
	// m_img = cv::imread(imagePath, cv::IMREAD_COLOR);	
	m_img = cv::imread(imagePath);	
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
std::string Image::Sample(double x, double y) const
{
	if (x < 0 || x > 1 || y < 0 || y > 1)
		return "";

	int col = floor(x * m_img.cols);	
	int row = floor(y * m_img.rows);	
	
	cv::Vec3b pixelValue = m_img.at<cv::Vec3b>(row, col);
	char c = pixelToCharacter(pixelValue);

	return colorCharacter(c, pixelValue);	
}

int Image::GetWidth() const
{
	return m_widthScale * m_img.cols;	
}

int Image::GetHeight() const
{
	return m_heightScale * m_img.rows;	
}


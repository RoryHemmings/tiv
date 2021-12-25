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

void Image::Display() const
{
	std::cout << "Width: " << GetWidth() << std::endl;
	std::cout << "Height: " << GetHeight() << std::endl;
}

int Image::GetWidth() const
{
	return m_widthScale * m_img.cols;	
}

int Image::GetHeight() const
{
	return m_heightScale * m_img.rows;	
}


#include <iostream>
#include "image.cpp"

Image::Image(Window* window, const std::string& imagePath, int maxWidth, int maxHeight, IMAGE_MODE=REGULAR)
	: m_window(window),
		m_mode(mode),
{
	m_img = cv::imread(imagePath, cv::IMREAD_COLOR);	
	if (m_img::data == NULL)
	{
		cerr << "Path: " << imagePath << " is invalid." << endl;
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
	std::cout << "Width: " << GetWidth() << endl;
	std::cout << "Height: " << GetHeight() << endl;
}

Image::GetWidth() const
{
	return m_widthScale * m_img.cols;	
}

Image::GetHeight() const
{
	return m_heightScale * m_img.rows;	
}


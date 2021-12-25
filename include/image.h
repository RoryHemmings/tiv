#ifndef TIV_IMAGE_H
#define TIV_IMAGE_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include <string>

enum IMAGE_MODE
{
	REGULAR,
	REGULAR_SHADED,
	REGULAR_COLOR,
	BLOCK_SHADED,
	BLOCK_COLOR
};

// Window forward declaration
class Window;

class Image
{
	public:
			// Constructor
		Image(Window* window, 
					const std::string& path, 
					int maxWidth, 
					int maxHeight, 
					IMAGE_MODE mode=REGULAR);

			// Mutators	
		void Resize(double widthScale, double heightScale);

			// Accessors
		char       Sample(double x, double y, double width, double height, COLOR& color) const;
		int  			 GetWidth() const;
		int  			 GetHeight() const;
		IMAGE_MODE GetMode() const { return m_mode; };

	private:
		Window* m_window;
		cv::Mat m_img;

		IMAGE_MODE m_mode;

		double m_widthScale;
		double m_heightScale;

};

#endif

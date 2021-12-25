#include <iostream>

#include "window.h"
#include "image.h"

int main(int argc, char** argv)
{
	// Window window(100, 100, "../img/test.png");
	Window window;
	Image testImage(&window, "img/test.png", 200, 150);
	testImage.Display();

	return 0;
}

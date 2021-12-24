#include <iostream>

#include "window.h"
#include "image.h"

int main(int argc, char** argv)
{
	// Window window(100, 100, "../img/test.png");
	Image testImage("../img/test.png", 1.0, 1.0);
	testImage.display();

	return 0;
}

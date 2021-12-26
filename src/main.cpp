#include <iostream>

#include "window.h"
#include "image.h"

int main(int argc, char** argv)
{
  Window window(50, 50);
	window.SetImage("img/test.png");
	window.Draw();

  return 0;
}

#ifndef TIV_WINDOW_H
#define TIV_WINDOW_H

#include <string>
#include <iostream>

#include "image.h"

class Window
{
	public:
		Window(int nRows, int nCols);
		~Window();

		void Draw();
		void SetImage(const std::string& path);

	private:
		void SetPosition(int row, int col);
		void Clear();

		Image* m_img;	
		int m_nRows, m_nCols; 
		int m_row, m_col; // Current position of cursor on the screen
};

#endif

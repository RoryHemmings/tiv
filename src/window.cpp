#include "window.h"

Window::Window(int nRows, int nCols)
	: m_nRows(nRows),
		m_nCols(nCols),
		m_img(nullptr),
		m_row(0),
		m_col(0)
{  }

Window::~Window()
{
	delete m_img;
}

void Draw()
{
  Clear();
  SetPosition(0, 0);
  for ( ;m_row < m_nRows; m_row++)
  {
    for ( ; m_col < m_nCols; m_col++)
    {
      cout << m_img->Sample(m_col/static_cast<double>(m_nCols), m_row/static_cast<double>(m_nRows));
    }
    cout << endl;
  }
}

void Window::SetPosition(int row, int col)
{
    // TODO Implement cursor movement
    m_row = row;
    m_col = col;
}

void Window::Clear()
{
  static const char* term = getenv("TERM");
  if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    cout << endl;
  else
  {
    static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
    cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
  }
}

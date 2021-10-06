#include "Score.h"

Score::Score()
{
	m_score = "0";
	m_text.Load("assets/text/fontbold.ttf", 100);
	m_text.SetColor(0, 255, 0, 255);
	m_text.SetDimension(200, 75);
}

Score::~Score()
{
	m_text.Unload();
}
void Score::SetScore(std::string score)
{
	m_score = score;
	m_text.SetText(m_score);
}

void Score::Render(Window& window)
{
	m_text.Render(680, 2, window);
}

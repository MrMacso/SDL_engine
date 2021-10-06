#pragma once
#include "GameObject.h"
#include "SDLText.h"

class Score : public GameObject
{

public:
	Score();
	~Score();

	void SetScore(std::string score);

	virtual void Update(Input& input) {}
	virtual void Render(Window& window);

private:
	SDLText m_text;

	std::string m_score;
};


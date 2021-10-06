#pragma once
#include <string>
#include <SDL.h>
#include "window.h"
#include "SDL_image.h"
#include <iostream>
#include <string>
#include "window.h"
class Sprite
{

public:

	enum Flip
	{
		NO_FLIP = SDL_FLIP_NONE,
		HORZ_FLIP = SDL_FLIP_HORIZONTAL,
		VERT_FLIP = SDL_FLIP_VERTICAL
	};

	Sprite();
	~Sprite();

	void IsAnimated(bool flag);
	void IsAnimationLooping(bool flag);


	void SetImageCel(int column, int row);
	void SetAnimationVelocity(float velocity);
	void SetSpriteDimension(int width, int height);
	void SetImageDimension(int columns, int rows, int width, int height);
	bool Load(const std::string& filename, Window& window);
	void Unload();

	void Update();
	void Render(int xPos, int yPos, double angle, Window& window, Flip flip = NO_FLIP);



private:

	int m_imageCel;

	float m_animationVelocity;
	bool m_isAnimated;
	bool m_isAnimationDead;
	bool m_isAnimationLooping;

	SDL_Texture* m_image;
	SDL_Point m_dimension;
	SDL_Point m_spriteDimension;
	SDL_Point m_imageDimension;

};


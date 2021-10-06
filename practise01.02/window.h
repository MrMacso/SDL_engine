#pragma once

#include <string>
#include <SDL.h>

class Window
{
public:
	bool Initialize(const std::string& windowTitle = "<No name>",
		int width = 1280, int height = 720);
	void Clear();
	void Present();
	void Shutdown();

	SDL_Renderer* GetRenderer();


private:
	SDL_Renderer* renderer;
	SDL_Window* window;

};


#include "window.h"
#include <SDL.h>
#include <iostream>


bool Window::Initialize(const std::string& windowTitle, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "error initalizing SDL." << std::endl;
		return false;
	}
	window = SDL_CreateWindow(windowTitle.c_str(),       
								SDL_WINDOWPOS_CENTERED,  
								SDL_WINDOWPOS_CENTERED,  
								width,                   
								height,                  
								0);                      
	if (!window)
	{
		std::cout << "error initalizing SDL." << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer)
	{
		std::cout << "Error creating renderer." << std::endl;
		return false;
	}
	return true;
}

void Window::Clear()
{
	SDL_RenderClear(renderer);
}

void Window::Present()
{
	SDL_RenderPresent(renderer);
}

void Window::Shutdown()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

SDL_Renderer* Window::GetRenderer()
{
	return renderer;
}

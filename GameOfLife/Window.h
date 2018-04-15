#pragma once
#include <SDL.h>
#include <iostream>

class Window
{
public:
	const int WIDTH;
	const int HEIGHT;
	const int SCALE;
	const char * TITLE;

private:
	SDL_Renderer * renderer;
	SDL_Window * window;
	SDL_Event event;
	SDL_Rect rect;

public:
	Window(const char * title, int width, int height, int scale);
	~Window();
	void DrawRect(int x, int y, int r, int g, int b);
	void Present();
	void Clear();

private:
	void Initialize();
};


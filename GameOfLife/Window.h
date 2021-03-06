#pragma once
#include <SDL.h>
#include <iostream>

class Window
{
public:
	const int WIDTH;
	const int HEIGHT;
	const int SCALE;
	const char *TITLE;

private:
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Rect rect;

public:
	Window(const char* title, int width, int height, int scale);
	~Window();
	void DrawRect(int x, int y, int r, int g, int b);
	void Present();
	void Clear(int r, int g, int b);

private:
	void Initialize();
};


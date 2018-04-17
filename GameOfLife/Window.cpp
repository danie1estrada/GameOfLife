#include "Window.h"

Window::Window(const char *title, int width, int height, int scale) :
	TITLE(title), WIDTH(width), HEIGHT(height), SCALE(scale) {
	Initialize();
}

Window::~Window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Window::Initialize() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Could not initialize SDL: " <<
		SDL_GetError() << std::endl;
		return;
	}
	window = SDL_CreateWindow(TITLE,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIDTH,
		HEIGHT,
		SDL_WINDOW_ALLOW_HIGHDPI);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	rect.w = SCALE;
	rect.h = SCALE;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Window::DrawRect(int x, int y, int r, int g, int b) {
	rect.x = x * SCALE;
	rect.y = y * SCALE;
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Window::Present() {
	SDL_RenderPresent(renderer);
}

void Window::Clear(int r, int g, int b) {
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}
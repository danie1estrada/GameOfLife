#pragma once
#include "GameOfLife.h"

class EventHandler
{
private:
	GameOfLife *game;

public:
	EventHandler(GameOfLife *game);
	~EventHandler();
	void ActionPerformed(SDL_Event);
	void MouseClick(SDL_Event);
	void KeyPressed(SDL_Event);
	void MouseMotion(SDL_Event);
};


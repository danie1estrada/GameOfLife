#include "EventHandler.h"

EventHandler::EventHandler(GameOfLife *game) {
	this->game = game;
}

EventHandler::~EventHandler() { }

void EventHandler::ActionPerformed(SDL_Event event) {
	switch (event.type) {
	case SDL_QUIT:
		game->Exit();
		break;
	case SDL_KEYDOWN:
		KeyPressed(event);
		break;
	case SDL_MOUSEBUTTONDOWN:
		MouseClick(event);
		break;
	case SDL_MOUSEMOTION:
		MouseMotion(event);
		break;
	}
}

void EventHandler::KeyPressed(SDL_Event event) {
	switch (event.key.keysym.sym) {
	case SDLK_s:
		game->PlayPause();
		break;
	case SDLK_c:
		game->Reset();
		break;
	case SDLK_PLUS:
		game->IncreaseSpeed();
		break;
	case SDLK_MINUS:
		game->DecreaseSpeed();
		break;
	case SDLK_KP_PLUS:
		game->IncreaseSpeed();
		break;
	case SDLK_KP_MINUS:
		game->DecreaseSpeed();
		break;
	}
}

void EventHandler::MouseClick(SDL_Event event) {
	int x = event.motion.x;
	int y = event.motion.y;

	if (event.button.button == SDL_BUTTON_LEFT) {
		game->ChangeState(x, y, true);
	}
	if (event.button.button == SDL_BUTTON_RIGHT) {
		game->ChangeState(x, y, false);
	}
}

void EventHandler::MouseMotion(SDL_Event event) {
	int x = event.motion.x;
	int y = event.motion.y;

	if (event.button.button == SDL_BUTTON_LEFT) {
		game->ChangeState(x, y, true);
	}
}
#include "EventHandler.h"

int main(int argc, char *argv[]) {
	
	GameOfLife game(100, 200, 5);
	EventHandler handler(&game);
	SDL_Event event;

	while (game.IsRunning()) {
		if (SDL_PollEvent(&event)) {
			handler.ActionPerformed(event);
		}
		if (!game.IsPaused()) {
			game.Play();
		}
	}

	return 0;
}
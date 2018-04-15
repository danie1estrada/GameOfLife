// #include "game_of_life.h"
// #include <SDL.h>

// void ActionPerformed(SDL_Event);

// GameOfLife game(100, 185, 10);
// SDL_Event event;

// int main(int argc, char * argv[]) {
	
// 	while (game.IsRunning()) {
// 		if (SDL_PollEvent(&event)) {
// 			ActionPerformed(event);
// 		}
// 		game.Play();
// 	}

// 	return 0;
// }

// void ActionPerformed(SDL_Event event) {
// 	switch (event.type) {
// 		case SDL_QUIT:
// 			game.Exit();
// 			break;
// 		case SDL_KEYDOWN:
// 			KeyPressed(event.key.keysym.sym);
// 			break;
// 		case SDL_MOUSEBUTTONDOWN:
// 			MouseClick(event);
// 			break;
// 		case SDL_MOUSEMOTION:
// 			break;
// 	}
// }

// void KeyPressed(int key) {
// 	switch (key) {
// 		case SDLK_s:
// 			break;
// 		case SDLK_c:
// 			break;
// 		case SDLK_PLUS:
// 			break;
// 		case SDLK_MINUS:
// 			break;
// 		case SDLK_KP_PLUS:
// 			break;
// 		case SDLK_KP_MINUS:
// 			break;
// 	}
// }

// void MouseClick(SDL_Event event) {
// 	int x = event.motion.x;
// 	int y = event.motion.y;
// 	if (event.button.button == SDL_BUTTON_LEFT) {
// 		game.ChangeState(x, y, true);
// 	}
// 	if (event.button.button == SDL_BUTTON_RIGHT) {
// 		game.ChangeState(x, y, false);
// 	}
// }
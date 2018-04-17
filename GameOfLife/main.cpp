/**
 * @file main.cpp
 * @version 2.0
 * @author Daniel Estrada
 * @title Main
 * @
 */
#include "EventHandler.h"
#include <thread>

void Something(GameOfLife *game);

int main(int argc, char *argv[]) {
	
	GameOfLife game(100, 190, 5);
	EventHandler handler(&game);
	SDL_Event event;

	std::thread t(Something, &game);

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

void Something(GameOfLife *game) {
	int answer, r, g, b;

	while (true) {
		std::cout << "Elija\n0. Color\n1. Fondo\nRespuesta: ";
		std::cin >> answer;
		std::cout << "Ingrese los valores: ";

		if (answer == 0) {
			std::cin >> r >> g >> b;
			game->SetColor(r, g, b);
		} else if (answer == 1) {
			std::cin >> r >> g >> b;
			game->SetBackgroundColor(r, g, b);
		}
		std::cout << std::endl;
	}
}
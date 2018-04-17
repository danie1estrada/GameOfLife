#include "GameOfLife.h"

GameOfLife::GameOfLife(int n_rows, int n_columns, int scale) :
	window("Conway's Game of Life", n_columns * scale, n_rows * scale, scale),
	ROWS(n_rows), COLUMNS(n_columns) {
	Initialize();
}

GameOfLife::~GameOfLife() {
	for (int i = 0; i < ROWS; i++) {
		delete[] grid[i];
		delete[] aux_grid[i];
	}
	delete[] grid;
	delete[] aux_grid;
	window.~Window();
}

void GameOfLife::Initialize() {
	speed = 40;
	running = true;
	playing = false;
	r = 0, g = 255, b = 100;
	bg_r = 0, bg_g = 0, bg_b = 0;

	grid = new bool *[ROWS];
	aux_grid = new bool *[ROWS];

	for (int i = 0; i < ROWS; i++) {
		grid[i] = new bool [COLUMNS];
		aux_grid[i] = new bool [COLUMNS];
		for (int j = 0; j < COLUMNS; j++) {
			grid[i][j] = 0;
			aux_grid[i][j] = 0;
		}
	}
}

int GameOfLife::NeighborsAlive(int curr_i, int curr_j) {
	int neighbors = 0;
	int row, col;
	for (int i = -1; i < 2; i++) {
		if (curr_i + i < 0 || curr_i + i >= ROWS) {
			row = curr_i + i < 0 ? ROWS - 1 : 0;
		} else {
			row = curr_i + i;
		}
		for (int j = -1; j < 2; j++) {
			if (curr_j + j < 0 || curr_j + j >= COLUMNS) {
				col = curr_j + j < 0 ? COLUMNS - 1 : 0;
			} else {
				col = curr_j + j;
			}
			if (aux_grid[row][col]) {
				neighbors++;
			}
		}
	}
	if (aux_grid[curr_i][curr_j]) {
		neighbors--;
	}
	return neighbors;
}

void GameOfLife::CopyGrid() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			aux_grid[i][j] = grid[i][j];
		}
	}
}

void GameOfLife::Play() {
	int n_alive = 0;
	CopyGrid();
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			n_alive = NeighborsAlive(i, j);
			if (aux_grid[i][j] == 1 && (n_alive > 3 || n_alive < 2)) {
				grid[i][j] = 0;
				window.DrawRect(j, i, bg_r, bg_g, bg_b);
			}
			else if (aux_grid[i][j] == 0 && n_alive == 3) {
				grid[i][j] = 1;
				window.DrawRect(j, i, r, g, b);
			}
		}
	}
	window.Present();
	SDL_Delay(speed);
}

void GameOfLife::ChangeState(int x, int y, bool value) {
	int i = y / window.SCALE;
	int j = x / window.SCALE;
	grid[i][j] = value;
	aux_grid[i][j] = value;

	if (value) {
		window.DrawRect(j, i, r, g, b);
	} else {
		window.DrawRect(j, i, bg_r, bg_g, bg_b);
	}
	window.Present();
}

void GameOfLife::Reset() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			grid[i][j] = 0;
			aux_grid[i][j] = 0;
		}
	}
	window.Clear(bg_r, bg_g, bg_b);
	playing = false;
}

void GameOfLife::Reload() {
	window.Clear(bg_r, bg_g, bg_b);
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (grid[i][j]) {
				window.DrawRect(j, i, r, g, b);
			}
		}
	}
	window.Present();
}

void GameOfLife::IncreaseSpeed() {
	if (speed > 10) {
		speed -= 10;
	} else if (speed > 0) {
		speed--;
	}
}

void GameOfLife::DecreaseSpeed() {
	if (speed < 100 && speed >= 10) {
		speed += 10;
	} else if (speed < 10) {
		speed++;
	}
}

void GameOfLife::SetColor(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
	Reload();
}

void GameOfLife::SetBackgroundColor(int r, int g, int b) {
	bg_r = r;
	bg_g = g;
	bg_b = b;
	Reload();
}

void GameOfLife::PlayPause() {
	playing = !playing;
}

bool GameOfLife::IsRunning() {
	return running;
}

bool GameOfLife::IsPaused() {
	return !playing;
}

void GameOfLife::Exit() {
	running = false;
}
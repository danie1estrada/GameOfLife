#include "game_of_life.h"

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
	running = true;
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
			row = curr_i + i < 0 ? COLUMNS - 1 : 0;
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
				window.DrawRect(j, i, 0, 0, 0);
			}
			else if (aux_grid[i][j] == 0 && n_alive == 3) {
				grid[i][j] = 1;
				window.DrawRect(j, i, 0, 255, 125);
			}
		}
	}
	window.Present();
}

void GameOfLife::ChangeState(int x, int y, bool value) {
	int i = y / window.SCALE;
	int j = x / window.SCALE;
	grid[i][j] = value;
	CopyGrid();

	if (value) {
		window.DrawRect(i, j, 0, 255, 125);
	} else {
		window.DrawRect(i, j, 0, 0, 0);
	}
	window.Present();
}

void GameOfLife::Exit() {
	running = false;
}

bool GameOfLife::IsRunning() {
	return running;
}
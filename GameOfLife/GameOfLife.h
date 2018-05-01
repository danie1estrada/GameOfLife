#pragma once
#include "Window.h"

class GameOfLife {
public:
	const int ROWS;
	const int COLUMNS;

private:
	Window window;
	bool **grid;
	bool **aux_grid;
	bool running;
	bool playing;
	unsigned int speed;
	unsigned int r, g, b;
	unsigned int bg_r, bg_g, bg_b;

public:
	GameOfLife(int n_rows, int n_columns, int scale);
	~GameOfLife();
	void Play();
	void Exit();
	bool IsRunning();
	bool IsPaused();
	void ChangeState(int x, int y, bool value);
	void IncreaseSpeed();
	void DecreaseSpeed();
	void PlayPause();
	void Reset();

private:
	void Initialize();
	void CopyGrid();
	int NeighborsAlive(int curr_i, int curr_j);
};


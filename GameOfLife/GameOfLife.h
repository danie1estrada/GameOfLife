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
	GameOfLife(int, int, int);
	~GameOfLife();
	void Play();
	void Exit();
	bool IsRunning();
	bool IsPaused();
	void ChangeState(int, int, bool);
	void IncreaseSpeed();
	void DecreaseSpeed();
	void PlayPause();
	void Reset();
	void SetColor(int, int, int);
	void SetBackgroundColor(int, int, int);
	void Reload();

private:
	void Initialize();
	void CopyGrid();
	int NeighborsAlive(int, int);
};


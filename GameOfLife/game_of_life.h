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

public:
	GameOfLife(int, int, int);
	~GameOfLife();
	void Play();
	void Exit();
	bool IsRunning();
	void ChangeState(int, int, bool);


private:
	void Initialize();
	void CopyGrid();
	int NeighborsAlive(int, int);
};


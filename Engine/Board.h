#pragma once

#include <random>
#include "Graphics.h"
#include "Vei2.h"

class Board
{
public:
	Board() = default;
	Board(int nFixedPoints);
	void Draw(Graphics& gfx) const;
	void Reset();
	void Update();
	void MovePoint();
	void AddPoint();
	void Delete();
	bool started = false;

public:
	int GetNumberDrawnPoints() const;

private:
	Vei2 movingPoint;

	int numberFixedPoints;
	Vei2* fixedPoints;

	int currNumberDrawnPoints = 0;
	Vei2* drawnPoints;

private:
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> pointIndexRange;
	std::uniform_int_distribution<int> xRange;
	std::uniform_int_distribution<int> yRange;
};
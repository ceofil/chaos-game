#include "Board.h"
#include <assert.h>

Board::Board(int nFixedPoints)
	:
	rng(rd()),
	numberFixedPoints(nFixedPoints),
	pointIndexRange(0, nFixedPoints - 1),
	xRange(0, Graphics::ScreenWidth - 1),
	yRange(0, Graphics::ScreenHeight - 1)
{
	assert(nFixedPoints > 0);
	Reset();
}

void Board::Update()
{
	AddPoint();
	MovePoint();
}



void Board::Draw(Graphics& gfx) const
{
	for (int i = 0; i < currNumberDrawnPoints; i++)
	{
		gfx.PutPixel(drawnPoints[i].x, drawnPoints[i].y, Colors::White);
	}
	for (int i = 0; i < numberFixedPoints; i++)
	{
		gfx.DrawCircle(fixedPoints[i].x, fixedPoints[i].y, 5.0f, Colors::Red);
	}
	gfx.DrawCircle(movingPoint.x, movingPoint.y, 5.0f, Color(255, 165, 0));
}

void Board::Reset()
{
	fixedPoints = new Vei2[numberFixedPoints];
	/*
	for (int i = 0; i < numberFixedPoints; i++)
	{
		int x = xRange(rng);
		int y = yRange(rng);
		fixedPoints[i] = Vei2(x, y);
	}
	*/
	fixedPoints[0] = Vei2(400,20);
	fixedPoints[1] = Vei2(20,580);
	fixedPoints[2] = Vei2(780, 580);
	
	movingPoint = fixedPoints[0];

	drawnPoints = new Vei2[Graphics::ScreenWidth * Graphics::ScreenHeight];
	currNumberDrawnPoints = 0;
}

void Board::MovePoint()
{
	const Vei2 chosenPoint = fixedPoints[pointIndexRange(rng)];
	movingPoint = ( movingPoint + chosenPoint ) / 2;
}

void Board::AddPoint()
{
	if(currNumberDrawnPoints + 1 < 800*600)
	drawnPoints[ currNumberDrawnPoints++ ] = movingPoint;
}

void Board::Delete()
{
	delete[] fixedPoints;
	fixedPoints = nullptr;

	delete[] drawnPoints;
	drawnPoints = nullptr;
}

int Board::GetNumberDrawnPoints() const
{
	return currNumberDrawnPoints;
}

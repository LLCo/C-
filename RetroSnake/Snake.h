#pragma once
//this class calculate the location of the snake,and generate point randomly;
//input: size of the table
#include <random>
#include <vector>
#include <stdio.h>
#include <tchar.h>
#include <thread>
#include <iostream>
#include <mutex>

#define COORD int
#define MAXTABLE 50


struct Point
{
	COORD x;
	COORD y;
};

enum gameStatu
{
	moveon,
	gameover,
	success
};

enum moveTo
{
	top,
	bottom,
	left,
	right
};

class Snake
{

	Point tableSize,point;
	int remindPoints;
	short table[MAXTABLE][MAXTABLE];
	std::vector<Point> snake;

public:
	Snake(const Point &tableSize);
	Snake();
	~Snake();
	gameStatu getGameStatu();
	bool updateGame(const moveTo &mt);
	bool showTheTable();

private:
	void initSnake();
	bool updateSnake(const moveTo &mt);
	bool updatePoint();
};


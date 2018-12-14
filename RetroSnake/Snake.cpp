#include "Snake.h"

Snake::Snake(const Point &tableSize = { 50, 50 })
{
	Snake::remindPoints = tableSize.x * tableSize.y; //
	initSnake();
	updatePoint();
	remindPoints -- ;
}

Snake::Snake()
{
	tableSize = { 50, 24 };
	Snake::remindPoints = tableSize.x * tableSize.y; //
	initSnake();
	updatePoint();
	remindPoints -- ;
}

Snake::~Snake()
{

}

gameStatu Snake::getGameStatu(){
	return gameover;
}

bool Snake::updateGame(const moveTo &mt){
	updateSnake(mt);
	return true;
}

void Snake::initSnake(){
	snake.push_back({ 5, 5 });
	snake.push_back({ 5, 6 });
	snake.push_back({ 5, 7 });
	snake.push_back({ 6, 7 });
	snake.push_back({ 7, 7 });
	snake.push_back({ 8, 7 });

	for(Point p : snake){
		table[p.x][p.y] = 1;
	}

	Snake::remindPoints -= 6;
};

bool Snake::updateSnake(const moveTo &mt){ //update snake's position and store it in vector'snake;

	Point snakeHead; // a point stand for head of retrosnake
	std::vector<Point>::iterator iterLastNum = snake.end() - 1;

	auto func = [&iterLastNum](const Point &point){
		Point returnPoint = { iterLastNum->x + point.x, iterLastNum->y + point.y };
		return returnPoint;
	};

	switch (mt)
	{
	case top :
		snakeHead = func({ 0, -1 });
		break;
	case bottom:
		snakeHead = func({ 0, 1 });
		break;
	case left:
		snakeHead = func({ -1, 0 });
		break;
	case right:
		snakeHead = func({ 1, 0 });
		break;
	}

	if (snakeHead.x<tableSize.x&&snakeHead.y<tableSize.y){

		if (table[snakeHead.x][snakeHead.y]==1){
			if (snakeHead.x == point.x && snakeHead.y == point.y){//retro snake eat the food! 
				snake.push_back(snakeHead);
				table[snakeHead.x][snakeHead.y] = 1;
				updatePoint(); //update the point when eat the food
				return true;
			}
			return false;
		}

		snake.push_back(snakeHead);
		table[snakeHead.x][snakeHead.y] = 1;//add snakeHead to table

		std::vector<Point>::iterator iter = snake.begin();
		table[iter->x][iter->y] = 0;//delete tail,reset the table.point;
		snake.erase(iter);
		return true;
	}
	return false;
};

bool Snake::updatePoint(){ //Every time the retrosnake get the food,call the method to generate a new food

	int targetPoints = 0;
	if (remindPoints != 0){

		std::random_device rd;
		int randNums = ((double)rd() / (double)std::random_device::max())*remindPoints;
		if (randNums>remindPoints){
			std::cout << "errod!" << std::endl;
		}

		//search the table,find the emply position
		for (int i = 0; i != tableSize.x; ++i)for (int j = 0; j != tableSize.y; ++j){
			if (table[i][j] != 1){
				if (targetPoints == randNums)  {
					table[i][j] = 1;
					point = { i, j};
					return true;
				}
				targetPoints++;
			}
		}
	}
	return false;
};

bool Snake::showTheTable(){

	for (int i = 0; i != tableSize.x + 2; i++){
		std::cout << "-";
	};
	std::cout << "\n";

	for (int i = 0; i != tableSize.y; i++){
		std::cout << "|";
		for (int j = 0; j != tableSize.x; j++){
			if (table[j][i] == 1){
				std::cout << "*";
			}
			else{
				std::cout << " ";
			}
		}
		std::cout << "|" << "\n";
	}

	for (int i = 0; i != tableSize.x + 2; i++){
		std::cout << "-";
	}
	std::cout << std::endl;
	return true;
}
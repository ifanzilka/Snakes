#include "SnakeGame.h"
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <time.h>
using namespace sf; // libary sfml


void SnakeGame::Tick() //next Position Snake
{
	//num-size Snake
	for (int i = num; i > 0; --i)   
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	//Key is press:
	if (dir == 0)s[0].y += 1;   //down
	if (dir == 1)s[0].x -= 1;	//left
	if (dir == 2)s[0].x += 1;	//right
	if (dir == 3)s[0].y -= 1;	//up

	
	//fruct is eating

	if ((s[0].x == f.x) && (s[0].y == f.y))
	{
		num++;
		f.x = rand() % N;
		f.y = rand() % M;

		score++;
		delay -= 0.075;//speed game

		if (delay < 0.15) delay = 0.15;


	}

	
	//Map border
	if (s[0].x >= N)s[0].x = 0;  if (s[0].x < 0) s[0].x = N - 1;
	if (s[0].y >= M)s[0].y = 0;  if (s[0].y < 0) s[0].y = M - 1;

	
	for (int i = 1; i < num; i++)
		if (s[0].x == s[i].x && s[0].y == s[i].y) endGame = true;


}

SnakeGame::SnakeGame()
{

	
}


SnakeGame::~SnakeGame()
{
}

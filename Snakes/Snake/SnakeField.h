#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <time.h>
using namespace sf; // libary sfml
#include "SnakeGame.h"
class SnakeField :public SnakeGame
{
private:

	int size = 15;

	int w = size * N;		//weight
	int h = size * M + 30;	//height
	const char *str= "SnakeGame";

	Texture t1, t2, t3, t4; //images block

	Sprite sprite1, sprite2, sprite3, sprite4;
	
	Font font;//רנטפע 
	RenderWindow window;

	Text text;
	Clock clock;

	float timer = 0; //delay==speed game
protected:
	void draw_Game();
	void EndGame();
	
public:

	
	
	void StartGame();
	
	

	
	SnakeField();
	~SnakeField();
};


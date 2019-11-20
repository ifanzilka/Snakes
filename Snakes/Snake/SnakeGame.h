#pragma once
class SnakeGame
{

protected:
	int N = 20, M = 20; //sizes game




	int score = 0;
	float delay = 0.5;

	int prev_keyboard = 0;


	//num-SnakeSize
	int dir, num = 4;



	struct Snake
	{
		int x;	int y;
	}	s[100];

	struct Fruct
	{
		int x, y;
	} f;
	
	bool endGame = false;;
public:

	void Tick();
	SnakeGame();
	~SnakeGame();
};


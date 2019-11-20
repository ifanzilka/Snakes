#include "SnakeField.h"
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <time.h>
using namespace sf; // libary sfml


void SnakeField::draw_Game()
{

	//draw
	window.clear();


	//draw map
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{

			sprite1.setPosition(i*size, j*size);
			window.draw(sprite1);
		}

	}

	//draw snake

	sprite3.setPosition(s[0].x*size, s[0].y*size);
	window.draw(sprite3);//brain

	for (int i = 1; i < num; i++)
	{
		sprite2.setPosition(s[i].x*size, s[i].y*size);
		window.draw(sprite2);
	}

	//draw fruit

	sprite4.setPosition(f.x*size, f.y*size);
	window.draw(sprite4);

	//draw score

	String s;
	s = "SCORE: ";
	s += std::to_string(score);

	text.setString(s);//задает строку тексту
	text.setPosition(10, (M)*size);//задаем позицию текста, центр камеры
	text.setFillColor(Color::Blue);
	window.draw(text);//рисую этот текст

	window.display();//draw Texture



	
}

void SnakeField::StartGame()
{
	HWND hConsole = GetConsoleWindow();//Если компилятор старый заменить на GetForegroundWindow()
	ShowWindow(hConsole, SW_HIDE);//собственно прячем оконо консоли
	srand(time(0));
	//start position fruit
	f.x = 10;
	f.y = 10;

	while (window.isOpen() && !endGame)
	{

		float time = clock.getElapsedTime().asSeconds();

		clock.restart();

		timer += time;

		Event e;

		while (window.pollEvent(e))
		{

			if (e.type == Event::Closed)
			{
				//int a=1;
				window.close();
			}

		}


		if ((Keyboard::isKeyPressed(Keyboard::Left)) && prev_keyboard != 2) dir = 1, prev_keyboard = 1;
		if ((Keyboard::isKeyPressed(Keyboard::Right)) && prev_keyboard != 1) dir = 2, prev_keyboard = 2;
		if ((Keyboard::isKeyPressed(Keyboard::Up)) && prev_keyboard != 0) dir = 3, prev_keyboard = 3;
		if ((Keyboard::isKeyPressed(Keyboard::Down)) && prev_keyboard != 3) dir = 0, prev_keyboard = 0;



		if (timer > delay)
		{
			timer = 0;
			Tick();
		}

		draw_Game();

	}

	EndGame();
	
}
void SnakeField::EndGame()
{
	//draw ENDGAME

	while (window.isOpen()) {

		window.clear();
		Event e;
		while (window.pollEvent(e))
		{

			if (e.type == Event::Closed)
			{
				//int a=1;
				window.close();
			}

		}

		text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
		Text text2(" ", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
		text2.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый

		String s1, s2;
		s1 = "TNE END!";
		s2 = "YOUR SCORE: ";
		s2 += std::to_string(score);

		text.setString(s1);//задает строку тексту
		text.setPosition(w / 2 - 80, h / 2 - 70);//задаем позицию текста, центр камеры
		text.setFillColor(Color::Red);

		text2.setString(s2);//задает строку тексту
		text2.setPosition(w / 2 - 80, h / 2 - 50);//задаем позицию текста, центр камеры
		text2.setFillColor(Color::Red);



		window.draw(text);//исую этот текст
		window.draw(text2);//исую этот текст


		window.display();//draw Texture



	}
}


SnakeField::SnakeField()
{


	//window
	window.create(VideoMode(w, h), "Snake Game!",sf::Style::Close);



	//texture
	t1.loadFromFile("images/white.png");
	t2.loadFromFile("images/red.png");
	t3.loadFromFile("images/snake.png");
	t4.loadFromFile("images/yellow.png");


	//OBJECT

	sprite1.setTexture(t1);
	sprite2.setTexture(t2);
	sprite3.setTexture(t3);
	sprite4.setTexture(t4);

	//
	font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта

	Text tex1("SCORE", font, 20);
	text = tex1;
	
	
	
}


SnakeField::~SnakeField()
{
}

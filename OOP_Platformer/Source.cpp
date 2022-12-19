#include<SFML/Graphics.hpp>
#include"GameObject.h"
#include"Player.h"
#include"GameManager.h"
#include"Platform.h"

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(800, 800), "Lesson 1. kychka-pc.ru");
	
	Texture tex,tex1;
	tex.loadFromFile("images\\char_black.png");
	Sprite s(tex);
	s.setTextureRect({ 0, 0, 128, 128 });
	tex1.loadFromFile("images\\platform.png");
	Sprite x(tex1);
	x.setTextureRect({ 0,404, 800,150 });
	Clock clock;
	clock.restart();

	GameManager GM;
	GM.AddObject(new Platform({ 400.f, 725.f }, { 800.f,150.f }, x));
	GM.AddObject(new Player({ 400.f, 400.f }, { 128.f, 128.f }, s));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float dt = clock.restart().asSeconds()*3;
		GM.Update(dt);

		window.clear();
		GM.Draw(window);
		window.display();
	}

	return 0;
}
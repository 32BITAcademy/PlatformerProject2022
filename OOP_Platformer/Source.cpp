#include<SFML/Graphics.hpp>
#include"GameObject.h"
#include"Player.h"
#include"GameManager.h"

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(200, 200), "Lesson 1. kychka-pc.ru");
	
	Texture tex;
	tex.loadFromFile("images\\mc.png");
	Sprite s(tex);
	s.setTextureRect({ 0, 0, 64, 64 });

	Clock clock;
	clock.restart();

	GameManager GM;
	GM.AddObject(new Player({ 100.f, 100.f }, { 64.f, 64.f }, s));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float dt = clock.restart().asSeconds();
		GM.Update(dt);

		window.clear();
		GM.Draw(window);
		window.display();
	}

	return 0;
}
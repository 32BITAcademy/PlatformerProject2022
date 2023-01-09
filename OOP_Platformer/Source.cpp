#include<SFML/Graphics.hpp>
#include<box2d/box2d.h>
#include"GameObject.h"
#include"Player.h"
#include"GameManager.h"
#include"Platform.h"


using namespace sf;

int main()
{
	

	RenderWindow window(sf::VideoMode(800, 800), "Platformer Project");
	
	Texture tex,tex1;
	tex.loadFromFile("images\\char_black.png");
	Sprite s(tex);
	s.setTextureRect({ 0, 0, 128, 128 });
	tex1.loadFromFile("images\\platform.png");
	Sprite sprite_plat1(tex1);
	Sprite sprite_plat2(tex1);
	Sprite sprite_plat3(tex1);
	sprite_plat1.setTextureRect({ 0,404, 800, 150 });
	sprite_plat2.setTextureRect({ 0,404, 400, 75 });
	sprite_plat3.setTextureRect({ 0,404, 75, 75 });
	Clock clock;
	clock.restart();

	GameManager* GM = GameManager::getInstance();
	GM->AddObject(new Platform({ 400.f, 725.f }, { 800.f,150.f }, sprite_plat1, true));
	GM->AddObject(new Platform({ 400.f, 425.f }, { 400.f,75.f }, sprite_plat2, true));
	GM->AddObject(new Platform({ 400.f, 300.f }, { 75.f,75.f }, sprite_plat3, false));
	GM->AddObject(new Player({ 400.f, 0.f }, { 50.f, 115.f }, s));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float dt = clock.restart().asSeconds();
		GM->World()->Step(dt, 5, 3);
		GM->Update(dt);

		window.clear(Color::White);
		GM->Draw(window);
		window.display();
	}

	return 0;
}
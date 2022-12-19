#pragma once
#include "GameObject.h"
class Platform :
    public GameObject
{
public:
	Platform(sf::Vector2f position, sf::Vector2f size, sf::Sprite sprite);
	~Platform();

	void Update(float dt);
	void SendMsg(MSG* m);
};


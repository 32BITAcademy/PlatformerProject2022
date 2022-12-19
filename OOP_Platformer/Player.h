#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	Player(sf::Vector2f position, sf::Vector2f size, sf::Sprite sprite);
	~Player();

	void Update(float dt);
	void SendMsg(MSG* m);
};


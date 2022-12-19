#include "Player.h"

using namespace sf;

Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Sprite sprite) :
	GameObject(position, size, sprite)
{

}

Player::~Player()
{
}

void Player::Update(float dt)
{
	static float speedx = 150,speedy=200;
	position.y += speedy * dt;
	position.x += speedx * dt;

	if (position.y > 200)
		speedy = -fabs(speedy);
	if (position.y < 0)
		speedy = fabs(speedy);
	if (position.x > 200)
		speedx = -fabs(speedx);
	if (position.x < 0)
		speedx = fabs(speedx);
}

void Player::SendMsg(MSG* m)
{
	;
}

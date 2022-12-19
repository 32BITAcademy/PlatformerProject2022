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
	static float speed = 100;
	position.x += speed * dt;

	if (position.x > 200)
		speed = -fabs(speed);
	if (position.x < 0)
		speed = fabs(speed);
}

void Player::SendMsg(MSG* m)
{
	;
}

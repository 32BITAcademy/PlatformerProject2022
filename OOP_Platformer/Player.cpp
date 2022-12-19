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
	static float speed = 150;
	
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		position.x -= speed * dt;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		position.x += speed * dt;
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		position.y -= speed * dt;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		position.y += speed * dt;
	}
	if (position.x < hitbox.width / 2)
		position.x = hitbox.width / 2;
	if (position.x > 800 - hitbox.width / 2)
		position.x = 800 - hitbox.width / 2;
	if (position.y < hitbox.height / 2)
		position.y = hitbox.height / 2;
	if (position.y > 800 - hitbox.height / 2)
		position.y = 800 - hitbox.height / 2;
}

void Player::SendMsg(MSG* m)
{
	;
}

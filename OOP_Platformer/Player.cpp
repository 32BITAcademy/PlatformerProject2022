#include "Player.h"
#include "GameManager.h"

using namespace sf;

Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Sprite sprite) :
	GameObject(position, size, sprite, b2_dynamicBody)
{
}

Player::~Player()
{
}

void Player::Update(float dt)
{
	static float speed = 3.50f;
	bool is_moving = false;
	b2Vec2 velocity = body->GetLinearVelocity();
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		is_moving = true;
		body->SetLinearVelocity({ -speed, velocity.y });
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		is_moving = true;
		body->SetLinearVelocity({ speed, velocity.y });
	}
	if (!is_moving)
	{
		body->SetLinearVelocity({ 0, velocity.y });
	}
}

void Player::SendMsg(MSG* m)
{
	;
}

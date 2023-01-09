#include "Player.h"
#include "GameManager.h"

using namespace sf;

Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Sprite sprite) :
	GameObject(position, size, sprite, b2_dynamicBody)
{
	body->DestroyFixture(body->GetFixtureList());
	b2FixtureDef fix_def;
	fix_def.shape = &shape;
	fix_def.density = 1;
	fix_def.friction = 0;
	body->CreateFixture(&fix_def);
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
		velocity.x = -speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		is_moving = true;
		velocity.x = speed;
	}
	if (!is_moving)
	{
		velocity.x = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		velocity.y = -1.5 * speed;
	}
	body->SetLinearVelocity(velocity);
}

void Player::SendMsg(MSG* m)
{
	;
}

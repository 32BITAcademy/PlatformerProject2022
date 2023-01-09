#include "GameObject.h"
#include "GameManager.h"

using namespace sf;

int GameObject::GenerateNewID()
{
	static int LastID = 0;
	return ++LastID;
}

GameObject::GameObject(Vector2f position, Vector2f size, Sprite sprite, b2BodyType body_type) :
	position(position), speed({ 0, 0 }), sprite(sprite)
{
	hitbox.width = size.x;
	hitbox.height = size.y;
	hitbox.left = position.x - size.x / 2;
	hitbox.top = position.y - size.y / 2;

	this->sprite.setOrigin({ size.x / 2, size.y / 2 });

	shape.SetAsBox((size.x / 2) * BOX_SCALE, (size.y / 2) * BOX_SCALE);
	body_def.position.Set(position.x * BOX_SCALE, position.y * BOX_SCALE);
	body_def.type = body_type;
	body_def.fixedRotation = true;
	GameManager* GM = GameManager::getInstance();
	body = GM->World()->CreateBody(&body_def);
	body->CreateFixture(&shape, 1);
}

GameObject::~GameObject()
{
}

int GameObject::GetID()
{
	return id;
}

void GameObject::Draw(sf::RenderWindow& win)
{
	b2Vec2 body_pos = body->GetPosition();
	position.x = body_pos.x / BOX_SCALE;
	position.y = body_pos.y / BOX_SCALE;

	sprite.setPosition(position);
	win.draw(sprite);
}

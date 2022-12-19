#include "GameObject.h"

using namespace sf;

int GameObject::GenerateNewID()
{
	static int LastID = 0;
	return ++LastID;
}

GameObject::GameObject(Vector2f position, Vector2f size, Sprite sprite) :
	position(position), speed({ 0, 0 }), sprite(sprite)
{
	hitbox.width = size.x;
	hitbox.height = size.y;
	hitbox.left = position.x - size.x / 2;
	hitbox.top = position.y - size.y / 2;

	this->sprite.setOrigin({ size.x / 2, size.y / 2 });
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
	sprite.setPosition(position);
	win.draw(sprite);
}

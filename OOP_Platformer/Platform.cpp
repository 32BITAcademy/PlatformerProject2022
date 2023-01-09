#include "Platform.h"
using namespace sf;
Platform::Platform(sf::Vector2f position, sf::Vector2f size, sf::Sprite sprite, bool is_static):
	GameObject(position,size,sprite, (is_static) ? b2_staticBody : b2_dynamicBody)
{
}

Platform::~Platform()
{
}

void Platform::Update(float dt)
{
}

void Platform::SendMsg(MSG* m)
{
}

#include "Platform.h"
using namespace sf;
Platform::Platform(sf::Vector2f position, sf::Vector2f size, sf::Sprite sprite):
	GameObject(position,size,sprite, b2_staticBody)
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

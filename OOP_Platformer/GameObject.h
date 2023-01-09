#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Graphics.hpp>
#include<box2d/box2d.h>
class MSG;

#define BOX_SCALE 0.01f

class GameObject
{
private:
	int id;
	b2PolygonShape shape;
	b2BodyDef body_def;

protected:
	b2Body* body;
	sf::Vector2f position;
	sf::Vector2f speed;
	sf::Rect<float> hitbox;
	sf::Sprite sprite;

public:
	static int GenerateNewID();

	GameObject(sf::Vector2f position, sf::Vector2f size, sf::Sprite sprite,
		b2BodyType body_type);
	virtual ~GameObject();

	int GetID();

	virtual void Update(float dt) = 0;
	virtual void SendMsg(MSG* m) = 0;
	virtual void Draw(sf::RenderWindow& win);
};
#pragma once
#include <SFML\Graphics.hpp>
class MSG;

class GameObject
{
private:
	int id;

protected:
	sf::Vector2f position;
	sf::Vector2f speed;
	sf::Rect<float> hitbox;
	sf::Sprite sprite;

public:
	static int GenerateNewID();

	GameObject(sf::Vector2f position, sf::Vector2f size, sf::Sprite sprite);
	virtual ~GameObject();

	int GetID();

	virtual void Update(float dt) = 0;
	virtual void SendMsg(MSG* m) = 0;
	virtual void Draw(sf::RenderWindow& win);
};
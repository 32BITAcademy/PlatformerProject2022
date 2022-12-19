#pragma once
#include<list>
#include<SFML/Graphics.hpp>

class GameObject;
class MSG;

class GameManager
{
private:
	std::list<GameObject*> objs;
	std::list<MSG*> msgs;

public:
	GameManager();
	~GameManager();

	void AddObject(GameObject* obj);
	void Update(float dt);
	void SendMsg(MSG* m);
	void Draw(sf::RenderWindow& win);
};


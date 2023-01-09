#pragma once
#include<list>
#include<SFML/Graphics.hpp>
#include<box2d/box2d.h>

class GameObject;
class MSG;

class GameManager
{
private:
	static GameManager* instance;

	std::list<GameObject*> objs;
	std::list<MSG*> msgs;
	b2World* world;
	GameManager();

public:
	static GameManager* getInstance();
	~GameManager();

	void AddObject(GameObject* obj);
	void Update(float dt);
	void SendMsg(MSG* m);
	void Draw(sf::RenderWindow& win);
	b2World* World();
};

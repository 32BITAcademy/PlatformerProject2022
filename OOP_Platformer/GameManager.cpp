#include "GameManager.h"
#include "GameObject.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() :
	objs(), msgs()
{
	b2Vec2 Gravity = { 0, 9.8f };
	world = new b2World(Gravity);
}

GameManager* GameManager::getInstance()
{
	if (instance == nullptr)
		instance = new GameManager();
	return instance;
}

GameManager::~GameManager()
{
	msgs.clear();
	objs.clear();
}

void GameManager::AddObject(GameObject* obj)
{
	objs.push_back(obj);
}

void GameManager::Update(float dt)
{
	for (auto o : objs)
		o->Update(dt);

	while(!msgs.empty())
	{
		MSG* m = msgs.front();
		for (auto o : objs)
			o->SendMsg(m);
		delete m;
		msgs.pop_front();
	}
}

void GameManager::SendMsg(MSG* m)
{
	msgs.push_back(m);
}

void GameManager::Draw(sf::RenderWindow& win)
{
	for (auto o : objs)
		o->Draw(win);
}

b2World* GameManager::World()
{
	return world;
}

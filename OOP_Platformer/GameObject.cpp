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

	IntRect tex_rect = sprite.getTextureRect();
	this->sprite.setOrigin({ tex_rect.width / 2.f, tex_rect.height / 2.f });

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

	RectangleShape debug_box({ hitbox.width, hitbox.height });
	debug_box.setOrigin({ hitbox.width / 2, hitbox.height / 2 });
	debug_box.setPosition(position);
	debug_box.setOutlineColor(Color::Red);
	debug_box.setOutlineThickness(1.5);
	debug_box.setFillColor(Color::Transparent);
	win.draw(debug_box);
}

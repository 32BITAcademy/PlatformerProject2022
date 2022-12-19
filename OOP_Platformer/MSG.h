#pragma once

class GameObject;

enum class MsgType {Create, Death, Move};

class MSG
{
public:
	MsgType type;
	GameObject* sender;
};


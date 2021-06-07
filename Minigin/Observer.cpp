#include "MiniginPCH.h"
#include "Observer.h"
#include "GameObject.h"

void dae::Achievement::OnNotify(const GameObject& entity, Event event)
{
	entity;
	switch (event)
	{
	case dae::Event::falling:
		break;
	case dae::Event::swimming:
		break;
	case dae::Event::loot:
		break;
	default:
		break;
	}
}

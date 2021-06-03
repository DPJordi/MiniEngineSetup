#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::GameObject::~GameObject() 
{
}

void dae::GameObject::Update()
{
	for (auto& currentComponent : m_pComponents)
	{
		currentComponent.second->Update();
	}
}
void dae::GameObject::Render() const
{
	for (auto& currentComponent : m_pComponents)
	{
		currentComponent.second->Render();
	}
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}

void dae::GameObject::AddComponent(const std::string ComponentName, std::shared_ptr<BaseComponent> newComponent)
{
#if _DEBUG
	for (auto component : m_pComponents)
	{
		if (component.first == ComponentName)
		{
			std::cout << "Component is already attached to this object.\n";
			return;
		}
	}
#endif
	std::pair<const std::string, std::shared_ptr<BaseComponent>> newPair = std::make_pair(ComponentName,newComponent);
	m_pComponents.insert(newPair);
}
void dae::GameObject::RemoveComponent(const std::string ComponentName)
{
	for (auto currentComponent : m_pComponents)
	{
		if (currentComponent.first == ComponentName)
		{
			m_pComponents.erase(currentComponent);
			break;
		}
	}
}

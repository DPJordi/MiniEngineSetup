#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include <set>


namespace dae
{
	class Texture2D;
	class BaseComponent;
	class Observer;

	class GameObject : public SceneObject
	{
	public:
		void Update() override;
		void Render() const override;

		void SetPosition(float x, float y);
		Transform GetTransform() const { return m_Transform; };

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void AddComponent(const std::string ComponentName, std::shared_ptr<BaseComponent> newComponent);
		void RemoveComponent(const std::string ComponentName);		
	private:
		Transform m_Transform;
		std::set<std::pair<const std::string, std::shared_ptr<BaseComponent>>> m_pComponents;
	};
}

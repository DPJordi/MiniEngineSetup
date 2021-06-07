#pragma once
#include <set>
#include "Observer.h"
namespace dae 
{
	class GameObject;

	class Subject
	{
	public:
		Subject() = default;
		virtual ~Subject() = default;

		void AddObserver(const std::string observerName, std::shared_ptr<Observer> newObserver);
		void RemoveObserver(const std::string observerName);
	protected:
		void OnNotify(const GameObject& entity, Event event);
	private:
		std::set<std::pair<const std::string, std::shared_ptr<Observer>>> m_pObservers;
	};
}


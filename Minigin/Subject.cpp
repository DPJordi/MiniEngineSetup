#include "MiniginPCH.h"
#include "Subject.h"

void dae::Subject::AddObserver(const std::string observerName, std::shared_ptr<Observer> newObserver)
{
#if _DEBUG
	for (auto currentObserver : m_pObservers)
	{
		if (currentObserver.first == observerName)
		{
			std::cout << "Observer is already attached to this object.\n";
			return;
		}
	}
#endif
	std::pair<const std::string, std::shared_ptr<Observer>> newPair = std::make_pair(observerName, newObserver);
	m_pObservers.insert(newPair);
}
void dae::Subject::RemoveObserver(const std::string observerName)
{
	for (auto currentObserver : m_pObservers)
	{
		if (currentObserver.first == observerName)
		{
			m_pObservers.erase(currentObserver);
			break;
		}
	}
}
void dae::Subject::OnNotify(const GameObject& entity, Event event)
{
	for (auto currentObserver : m_pObservers)
	{
		currentObserver.second->OnNotify(entity,event);
	}
}
#pragma once

namespace dae 
{
	class GameObject;

	enum class Event
	{
		falling,
		swimming,
		loot
	};

	class Observer
	{
	public:
		virtual ~Observer() = default;
		virtual void OnNotify(const GameObject& entity, Event event) = 0;
	};

	class Achievement final : public Observer
	{
	public:
		Achievement() = default;
		~Achievement() override = default;

		void OnNotify(const GameObject& entity, Event event) override;
	private:
		//void Unlock();
	};
}



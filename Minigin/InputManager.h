#pragma once
#include <XInput.h>
#include "Singleton.h"

namespace dae
{
	class Command;
	enum class ControllerButton
	{
		ButtonA,
		ButtonB,
		ButtonX,
		ButtonY,
		DPAD_UP,
		DPAD_DOWN,
		DPAD_LEFT,
		DPAD_RIGHT,
		Left_Tumb,
		Right_Thumb,
		Left_Shoulder,
		Right_Shoulder,
		Start,
		Back,
		bLeftTrigger,
		bRightTrigger,
		ThumbLX,
		ThumbLY,
		ThumbRX,
		ThumbRY
	};

	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();
		bool IsPressed(ControllerButton button) const;
		std::shared_ptr<Command> ProcessAnotherController();

	private:
		XINPUT_STATE m_CurrentState{};
		std::shared_ptr<Command> m_ButtonA;
		std::shared_ptr<Command> m_ButtonB;
		std::shared_ptr<Command> m_ButtonY;
		std::shared_ptr<Command> m_ButtonX;

		bool ProcessController();
		bool ProcessKeyboard();
	};

}

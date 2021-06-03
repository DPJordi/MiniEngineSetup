#pragma once
#include <XInput.h>
#include "Singleton.h"
#include "Command.h"

namespace dae
{
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
	private:
		XINPUT_STATE m_CurrentState{};
		std::unique_ptr<Command> m_ButtonA;
		std::unique_ptr<Command> m_ButtonB;
		std::unique_ptr<Command> m_ButtonY;
		std::unique_ptr<Command> m_ButtonX;

		bool ProcessController();
		bool ProcessKeyboard();
	};

}

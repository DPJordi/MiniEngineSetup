#include "MiniginPCH.h"
#include "InputManager.h"
#include <SDL.h>
#include "Command.h"



bool dae::InputManager::ProcessInput()
{
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &m_CurrentState);
	
	bool controllerResult = ProcessController();
	bool keyboardResult = ProcessKeyboard();
	
	return controllerResult && keyboardResult;
}

bool dae::InputManager::ProcessController()
{
	if (IsPressed(ControllerButton::Back))
	{
		std::cout << "back button\n";
		return false;
	}
	return true;
}
bool dae::InputManager::IsPressed(ControllerButton button) const
{
	switch (button)
	{
	case dae::ControllerButton::ButtonA:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_A;
		break;
	case dae::ControllerButton::ButtonB:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_B;
		break;
	case dae::ControllerButton::ButtonX:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_X;
		break;
	case dae::ControllerButton::ButtonY:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_Y;
		break;
	case dae::ControllerButton::DPAD_UP:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP;
		break;
	case dae::ControllerButton::DPAD_DOWN:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN;
		break;
	case dae::ControllerButton::DPAD_LEFT:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT;
		break;
	case dae::ControllerButton::DPAD_RIGHT:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT;
		break;
	case dae::ControllerButton::Left_Tumb:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB;
		break;
	case dae::ControllerButton::Right_Thumb:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB;
		break;
	case dae::ControllerButton::Right_Shoulder:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER;
		break;
	case dae::ControllerButton::Left_Shoulder:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER;
		break;
	case dae::ControllerButton::Start:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_START;
		break;
	case dae::ControllerButton::Back:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_BACK;
		break;
	case dae::ControllerButton::bLeftTrigger:
		//if(m_CurrentState.Gamepad.bLeftTrigger && m_CurrentState.Gamepad.bLeftTrigger < XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
		return m_CurrentState.Gamepad.bLeftTrigger / 255.0f;
		break;
	case dae::ControllerButton::bRightTrigger:
		return m_CurrentState.Gamepad.bRightTrigger / 255.0f;
		break;
	case dae::ControllerButton::ThumbLX:
		return false;// m_CurrentState.Gamepad.sThumbLX / 255.0f;
		break;
	case dae::ControllerButton::ThumbLY:
		return false;//m_CurrentState.Gamepad.sThumbLY / 255.0f;
		break;
	case dae::ControllerButton::ThumbRX:
		return false;// m_CurrentState.Gamepad.sThumbRX / 255.0f;
		break;
	case dae::ControllerButton::ThumbRY:
		return false;// m_CurrentState.Gamepad.sThumbRY / 255.0f;
		break;
	default:
		return false;
		break;
	}
}
bool dae::InputManager::ProcessKeyboard()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) {
		switch (e.type)
		{
		case SDL_QUIT:
			return false;
			break;
		case SDL_KEYDOWN:
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				return false;
			}
			break;
		case SDL_KEYUP:
			break;
		case SDL_MOUSEMOTION:
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		case SDL_MOUSEBUTTONUP:
			break;
		}
	}
	return true;
}

std::shared_ptr<dae::Command> dae::InputManager::ProcessAnotherController()
{
	if (IsPressed(ControllerButton::ButtonA))
	{
		m_ButtonA = std::make_shared<KillCommand>();
		return m_ButtonA;
	}
	else if (IsPressed(ControllerButton::ButtonB))
	{
		m_ButtonB = std::make_shared<FartCommand>();
		return m_ButtonB;
	}
	else if (IsPressed(ControllerButton::ButtonX))
	{
		return m_ButtonX;
	}
	else if (IsPressed(ControllerButton::ButtonY))
	{
		return m_ButtonY;
	}

	return NULL;
}

#include "MiniginPCH.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <SDL.h>
#include "TextObject.h"
#include "GameObject.h"
#include "Scene.h"

#include "Command.h"
#include "componentInclude.h"

using namespace std;
using namespace std::chrono;

std::shared_ptr<dae::GameObject> g_Qbert;

void dae::Minigin::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 exam assignment", //title
		SDL_WINDOWPOS_UNDEFINED, // x-coordinate/axis?
		SDL_WINDOWPOS_UNDEFINED, //y-coordinate/axis?
		640, //width 640
		480, //height 480
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);
}

/**
 * Code constructing the scene world starts here
 */
void dae::Minigin::LoadGame() const
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_shared<GameObject>();
	go->SetPosition(0.f, 0.f);
	go->AddComponent("Texture2D",std::make_shared<Texture2DComponent>("background.jpg", go->GetTransform()));
	scene.Add(go);

	go = std::make_shared<GameObject>();
	go->SetPosition(200, 120);
	go->AddComponent("Texture2D",std::make_unique<Texture2DComponent>("logo.png", go->GetTransform()));
	scene.Add(go);

	g_Qbert = std::make_shared<GameObject>();
	g_Qbert->SetPosition(10.f,10.f);
	g_Qbert->AddComponent("Texture2D", std::make_unique<Texture2DComponent>("logo.png", g_Qbert->GetTransform()));
	g_Qbert->AddComponent("Lives", std::make_shared<LivesComponent>(ResourceManager::GetInstance().LoadFont("Lingua.otf", 20), g_Qbert->GetTransform()));
	scene.Add(g_Qbert);

	//auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
}

void dae::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}
void dae::Minigin::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();

		bool doContinue = true;
		while (doContinue)
		{
			const auto currentTime = high_resolution_clock::now();
			
			doContinue = input.ProcessInput();
			std::shared_ptr<Command> givenCommand = input.ProcessAnotherController();
			if (givenCommand)
			{
				givenCommand->Execute(*g_Qbert);
			}
			sceneManager.Update();
			renderer.Render();
			
			auto sleepTime = duration_cast<duration<float>>(currentTime + milliseconds(MsPerFrame) - high_resolution_clock::now());
			this_thread::sleep_for(sleepTime);
		}
	}

	Cleanup();
}

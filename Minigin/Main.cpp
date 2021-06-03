#include "MiniginPCH.h"

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#include <vld.h>
#endif

#include "SDL.h"
#include "Minigin.h"

int main(int, char*[]) 
{
	//this can be considered the entry point.

	//startup, initialise which 'game' we run.
	dae::Minigin engine;

	//we run the game (application)
	engine.Run();


    return 0;
}
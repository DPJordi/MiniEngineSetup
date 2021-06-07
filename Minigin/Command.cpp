#include "MiniginPCH.h"
#include "Command.h"
#include <iostream>
#include "GameObject.h"
#include "LivesComponent.h"

dae::KillCommand::KillCommand()
{
}
dae::KillCommand::~KillCommand()
{
} 
void dae::KillCommand::Execute(GameObject& actor)
{
	actor;
}
void dae::KillCommand::Undo()
{

}

dae::FartCommand::FartCommand()
{
}
dae::FartCommand::~FartCommand()
{
}
void dae::FartCommand::Execute(GameObject& actor)
{
	actor;
}
void dae::FartCommand::Undo()
{

}
#include "MiniginPCH.h"
#include "Command.h"
#include <iostream>

FireCommand::FireCommand()
{
}
FireCommand::~FireCommand()
{
}
void FireCommand::Execute()
{
	std::cout << "Pew pew\n";
}
void FireCommand::Undo()
{

}

DuckCommand::DuckCommand()
{
}
DuckCommand::~DuckCommand()
{
}
void DuckCommand::Execute()
{
	std::cout << "Knees weak\n";
}
void DuckCommand::Undo()
{

}

JumpCommand::JumpCommand()
{
}
JumpCommand::~JumpCommand()
{
}
void JumpCommand::Execute()
{
	std::cout << "Jump for joy\n";
}
void JumpCommand::Undo()
{

}

FartCommand::FartCommand()
{
}
FartCommand::~FartCommand()
{
}
void FartCommand::Execute()
{
	std::cout << "*fart noises*\n";
}
void FartCommand::Undo()
{

}
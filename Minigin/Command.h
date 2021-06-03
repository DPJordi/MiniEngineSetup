#pragma once
class Command
{
public:
	Command() = default;
	virtual ~Command() = default;
	virtual void Execute() = 0;
	virtual void Undo() = 0;
};

class FireCommand final : public Command
{
public:
	FireCommand();
	~FireCommand() override;
	void Execute() override;
	void Undo() override;
private:

};

class DuckCommand final : public Command
{
public:
	DuckCommand();
	~DuckCommand() override;
	void Execute() override;
	void Undo() override;
private:

};

class JumpCommand final : public Command
{
public:
	JumpCommand();
	~JumpCommand() override;
	void Execute() override;
	void Undo() override;
private:

};

class FartCommand final : public Command
{
public:
	FartCommand();
	~FartCommand() override;
	void Execute() override;
	void Undo() override;
private:

};





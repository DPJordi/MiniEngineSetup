#pragma once
namespace dae
{
	class GameObject;

	class Command
	{
	public:
		Command() = default;
		virtual ~Command() = default;
		virtual void Execute(GameObject& actor) = 0;
		virtual void Undo() = 0;
	};

	class KillCommand final : public Command
	{
	public:
		KillCommand();
		~KillCommand() override;
		void Execute(GameObject& actor) override;
		void Undo() override;
	private:

	};

	class FartCommand final : public Command
	{
	public:
		FartCommand();
		~FartCommand() override;
		void Execute(GameObject& actor) override;
		void Undo() override;
	private:

	};
}








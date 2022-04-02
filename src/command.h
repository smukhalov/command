#pragma once

class ICommand {
public:
	virtual void Do() = 0;
	virtual void Undo() = 0;

	virtual ~ICommand() = default;
};

#pragma once

#include <string>
#include <memory>
#include <vector>

#include "command.h"

class Document {
	friend class AppendCommand;

public:
	void Append(const std::string& text);

	void Undo();
	void ToString();

private:
	std::string content;
	std::vector<std::unique_ptr<ICommand>> commands;

	void AddCommand(std::unique_ptr<ICommand> command);
	void AppendText(const std::string& text);
	void PopBack(size_t length);
};

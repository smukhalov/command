#pragma once

#include <string>
#include "command.h"

class Document;

class AppendCommand: public ICommand {
public:
	AppendCommand(Document& doc_, const std::string& text_); // : doc(doc_), text(text_) {}

	void Do() override;
	void Undo() override;

private:
	Document& doc;
	std::string text;
};

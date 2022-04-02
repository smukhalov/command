#include <string>
#include "append_command.h"
#include "document.h"

AppendCommand::AppendCommand(Document& doc_, const std::string& text_): doc(doc_), text(text_) {}

void AppendCommand::Do() {
	doc.AppendText(text);
}

void AppendCommand::Undo() {
	doc.PopBack(text.size());
}

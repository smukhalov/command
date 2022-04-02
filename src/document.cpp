#include <string>
#include <memory>
#include <vector>
#include <iostream>

#include "append_command.h"
#include "document.h"

void Document::Append(const std::string& text){
	AddCommand(std::make_unique<AppendCommand>(*this, text));

	commands.back()->Do();
}

void Document::Undo(){
	if(commands.empty()){
		return;
	}

	commands.back()->Undo();
	commands.pop_back();
}

void Document::AddCommand(std::unique_ptr<ICommand> c){
	commands.push_back(std::move(c));
}

void Document::AppendText(const std::string& text){
	content.append(text);
}

void Document::PopBack(size_t length){
	if(length >= content.size()){
		content.clear();
	} else {
		content = content.substr(0, content.size() - length);
	}
}

void Document::ToString(){
	std::cout << "Content - " << content << '\n';
}




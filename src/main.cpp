#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "append_command.h"
#include "document.h"

/*class Auto;

class Person {
public:
    Person(Auto& a_, std::string n): a(a_), name(n)
    {}

    void drive();
    void setPrice(int price);

private:
    Auto& a;
    std::string name;
};

class Auto {
    friend class Person;
public:
    Auto(std::string autoName, int autoPrice)
    {
        name = autoName;
        price = autoPrice;
    }
    std::string getName() { return name; }
    int getPrice() { return price; }

private:
    std::string name;   // название автомобиля
    int price;  // цена автомобиля
};

void Person::drive() {
    std::cout << name << " drives " << a.name << std::endl;
}
void Person::setPrice(int price) {
    if (price > 0)
    	a.price = price;
}*/

//class ICommand {
//public:
//	virtual void Do() = 0;
//	virtual void Undo() = 0;
//
//	virtual ~ICommand() = default;
//};

/*class Document;

class AppendCommand: public ICommand {
public:
	AppendCommand(Document& doc_, const std::string& text_): doc(doc_), text(text_) {}

	void Do() override;
	void Undo() override;
	void Do() override {
		doc.AppendText(text);
	}

	void Undo() override {
		doc.PopBack(text.size());
	}

private:
	Document& doc;
	std::string text;
};*/

/*class Document {
	friend class AppendCommand;

public:
	void Append(const std::string& text){
		AddCommand(std::make_unique<AppendCommand>(*this, text));
	}

	void Undo();



private:
	void AddCommand(std::unique_ptr<ICommand> command);
	std::vector<std::unique_ptr<ICommand>> commands;

	void AppendText(const std::string& text){
		//;
	}
	void PopBack(size_t length){
		//;
	}
};*/

/*void AppendCommand::Do() {
	doc.AppendText(text);
}

void AppendCommand::Undo() {
	doc.PopBack(text.size());
}*/

/*void Document::Undo(){
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
	//
}
void Document::PopBack(size_t length){
	//
}*/

int main() {
	//const std::string c("Test1");
	Document d;

	d.Append("Text1 text2");
	d.ToString();

	d.Append("Text3 text4");
	d.ToString();

	d.Undo();
	d.ToString();

	d.Undo();
	d.ToString();

	//d.Append("Test2");

	/*Auto tesla("Tesla", 5000);
	Person tom(tesla, "Tom");
	tom.drive();
	tom.setPrice(8000);
	std::cout << tesla.getName() << " : " << tesla.getPrice() << std::endl;*/

	return 0;
}

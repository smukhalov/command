/*#include <string>

class Auto;

class Person
{
public:
    Person(std::string n)
    {
        name = n;
    }
    void drive(Auto &a);
    void setPrice(Auto &a, int price);

private:
    std::string name;
};

class Auto
{
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

void Person::drive(Auto &a)
{
    std::cout << name << " drives " << a.name << std::endl;
}
void Person::setPrice(Auto &a, int price)
{
    if (price > 0)
        a.price = price;
}*/

/*
#include <string>
#include <memory>
#include <vector>

using namespace std;

class ICommand {
public:
	virtual void Do() = 0;
	virtual void Undo() = 0;

	virtual ~ICommand() = default;
};

class Document;

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
};

class Document {
	friend class AppendCommand;

public:
	void Append(const std::string& text){
		AddCommand(std::make_unique<AppendCommand>(*this, text));
	}

	void Undo();

	void AppendText(const std::string& text);
	void PopBack(size_t length);

private:
	void AddCommand(std::unique_ptr<ICommand> command);
	std::vector<std::unique_ptr<ICommand>> commands;
};

void AppendCommand::Do() {
	doc.AppendText(text);
}

void AppendCommand::Undo() {
	doc.PopBack(text.size());
}

void Document::Undo(){
	if(commands.empty()){
		return;
	}

	commands.back()->Undo();
	commands.pop_back();
}
*/

#include <iostream>
#include <fstream>
#include <conio.h>
#include <unordered_map>
#include <stdlib.h>
#include <string>
#define CONTACTS "contacts.txt"



//GENERATED_OUTPUT

template<class T>
struct Node;

template<class T>
std::ostream& operator <<(std::ostream& os, const Node<T>& other);

template<class T>
std::ostream& operator <<(std::ostream& os, Node<T>* other);


template<class T> 
struct Node
	
{
	T value;
	Node* next = nullptr;
	Node* prev = nullptr;

	Node() {}

	//Operators
	bool operator ==(const Node & other)
	{
		return value == other.value;
	}

	friend std::ostream& operator << <>(std::ostream& os, const Node<T> & other);
	friend std::ostream& operator << <>(std::ostream& os, Node<T>* other);
};

template<class T>
std::ostream& operator <<(std::ostream& os, const Node<T>& other)
{
	os << other->value;
	return os;
}

template<class T>
std::ostream& operator <<(std::ostream& os, Node<T>* other)
{
	os << other->value;
	return os;
}
template<class T>
struct Node;

template<class T>
std::ostream& operator <<(std::ostream& os, const Node<T>& other);

template<class T>
std::ostream& operator <<(std::ostream& os, Node<T>* other);

template<class T>
class DoublyLinkedList;

template<class T>
std::ostream& operator <<(std::ostream& os, const DoublyLinkedList<T>& other);


template<class T>
class DoublyLinkedList
	
{
public:

	DoublyLinkedList() {};
	DoublyLinkedList(T value) 
	{
		add_back(value);
	}

	Node<T> * create_node(T value)
	{
		Node<T>* new_node = new Node<T>;
		new_node->value = value;
		new_node->next = nullptr;
		new_node->prev = nullptr;
		return new_node;
	}

	void add_front(T value)
	{
		Node<T>* node = create_node(value);

		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			head->prev = node;
			node->next = head;
			head = node;
		}

		size++;
	}

	void add_back(T value)
	{
		Node<T>* node = create_node(value);

		if (tail == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			node->prev = tail;
			tail = node;
		}

		size++;
	}

	void add_pos(T value, int pos)
	{
		if (pos > size)
			return;

		Node<T>* node = create_node(value);
		Node<T>* next = head;

		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			while (pos)
			{
				next = next->next;
				pos--;
			}

			if (next == head)
				head = node;
			else if (next == tail)
				tail = node;

			if (next->prev != nullptr)
				next->prev->next = node;

			next->prev = node;
			node->prev = next->prev;
			node->next = next;
		}

		size++;
	}

	void delete_front()
	{
		Node<T>* next = head;

		if (head == nullptr)
			return;

		head = head->next;

		if(head != nullptr)
			head->prev = nullptr;

		delete next;
		size--;
	}

	void delete_back()
	{
		Node<T>* next = tail;

		if (tail == nullptr)
			return;

		tail = tail->prev;

		if (tail != nullptr)
			tail->next = nullptr;

		delete next;
		size--;
	}

	void delete_pos(int pos)
	{
		if (pos > size || head == nullptr)
			return;

		Node<T>* next = head;

		while (pos)
		{
			next = next->next;
			pos--;
		}

		delete_node(next);
	}

	bool delete_node(Node<T>* next)
	{
		if (next == nullptr)
			return false;

		if (next == head)
			head = next->next;
		else if (next == tail)
			tail = next->prev;

		if (next->prev != nullptr)
			next->prev->next = next->next;

		if (next->next != nullptr)
			next->next->prev = next->prev;

		delete next;
		size--;
		return true;
	}

	Node<T> * search(T value)
	{
		Node<T>* next = head;

		while (next != nullptr)
		{
			if (next->value == value)
				return next;

			next = next->next;
		}

		return nullptr;
	}

	Node<T>* search_pos(unsigned int value)
	{
		if (value >= size)
			return nullptr;

		Node<T>* next = head;

		while (value)
		{
			next = next->next;
			value--;
		}

		return next;
	}

	bool delete_value(T value)
	{
		Node<T>* next = search(value);

		if (next == nullptr)
			return false;

		return delete_node(next);
	}

	void clear()
	{
		if (head == nullptr)
			return;

		Node<T>* next = head->next;

		while (head != nullptr)
		{
			delete head;
			head = next;

			if (next != nullptr)
				next = next->next;
		}

		size = 0;
	}

	virtual ~DoublyLinkedList()
	{
		clear();
	}

	//Operators
	Node<T>& operator [](unsigned int i)
	{
		return *search_pos(i);
	}

	friend std::ostream& operator << <>(std::ostream& os, const DoublyLinkedList<T>& other);

private:
	
public:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	bool print_numbered = false;
	const char* print_prefix = nullptr;
	unsigned int size = 0;
	bool print_spacing = true;
};

template <class T>
std::ostream& operator <<(std::ostream& os, const DoublyLinkedList<T>& other) 
{
	Node<T>* next = other.head;
	int i = 0;
	while (next != other.tail && next != nullptr)
	{
		if (other.print_prefix != nullptr)
			os << other.print_prefix;

		if(other.print_numbered)
			os << i++ << ". ";

		os << next->value << (other.print_spacing == true ? " " : "");
		next = next->next;
	}

	if (next != nullptr)
	{
		if (other.print_prefix != nullptr)
			os << other.print_prefix;

		if (other.print_numbered)
			os << i++ << ". ";

		os << next->value;
	}

	os << "\n";

	return os;
}
using namespace std;

struct p
{
	string name = "";
	string phone = "";

	//Operators
	bool operator == (const p& other)
	{
		return this->phone == other.phone;
	}

	friend std::ostream& operator <<(std::ostream& os, const p& other);
};

std::ostream& operator <<(std::ostream& os, const p& other)
{
	os << "Person name: " << other.name << ", Phone number: " << other.phone << "\n";
	return os;
}

unordered_map<string, DoublyLinkedList<p>> map;

void saveContact(const p &person){
	string name = person.name;
	string phone = person.phone;
	fstream savedContacts;
	savedContacts.open(CONTACTS, std::fstream::app);
	string line;
	savedContacts<<name<<"\n"<<phone<<"\n";
	savedContacts.close();
}

void removeFromFile(const string &field){
	fstream savedContacts;
	savedContacts.open(CONTACTS);
	string line, temp = "";
	while(getline(savedContacts, line))	if (line != field) temp += line + "\n";
	savedContacts.close();
	savedContacts.open(CONTACTS, std::ofstream::out | std::ofstream::trunc);
	savedContacts<<temp;
}

void removeAllFromFile(){
	fstream savedContacts;
	savedContacts.open(CONTACTS, std::ofstream::out | std::ofstream::trunc);
	savedContacts.close();
}

void add_dup(const string& name, const p& person, bool use_save = false)
{
	string tmp = "";
	for (int i = 0; i < name.length(); i++) {
		tmp += tolower(name[i]);
		map[tmp].add_back(person);
		map[tmp].print_numbered = true;
		map[tmp].print_prefix = "\t";
	}
	if(use_save == true)
		saveContact(person);
}

void populate_map_from_file(){
	fstream savedContacts;
	savedContacts.open(CONTACTS);
	string name, number;
	while (getline(savedContacts, name))
	{
		getline(savedContacts, number);
		p person;
		person.name = name;
		person.phone = number;
		add_dup(name, person);
		add_dup(number, person);
	}
	savedContacts.close();
}


void addLetter(string& prevWord, const char& newLetter){
	if (newLetter != 8) prevWord.push_back(newLetter);
	else if (newLetter == 8 && prevWord.size() > 0) prevWord.pop_back(); //backspace
	return;
}

void printNames(const string& name) {
	cout << "\nContacts: ";
		if (name == "") return;
		else
		{
			cout << "\n" << map[name];
			if(map[name].size == 0) //strange map behaviour
				map.erase(name);
		}
}

string inputName(string& name) {
	cout << "\nInput name/phone: "<<name;
	
	char letter = tolower(_getch());
	if (letter == '\r') return name; //enter
	else addLetter(name, letter);
	
	printNames(name);
	return inputName(name);
}

void delete_all_by_entry(const string &field, const string & phone)
{
	string tmp = "";
	//make a copy
	p person;
	person.phone = phone;

	for (int i = 0; i < field.length(); i++){
		tmp += tolower(field[i]);
		DoublyLinkedList<p>& list = map[tmp];
		list.delete_node(list.search(person));
		if (list.size == 0)
			map.erase(tmp);	
	}
}

void deleteByChar() {
	string blank;
	string name = inputName(blank);
	
	int index;
	if (map[name].size != 0)
	{
		while (map[name].size == 0) {
			cout << "Please try again\n";
			name = inputName(blank);
		}

		cout << "\nDelete which contact?:\n";
		cin >> index;
		while (index < 0 || index >= map[name].size) {
			cout << "Please try again\n";
			cin >> index;
		}
	}

	if (map[name].size != 0)
	{
		string tmp_name = map[name].search_pos(index)->value.name;
		removeFromFile(tmp_name);
		string tmp_phone = map[name].search_pos(index)->value.phone;
		removeFromFile(tmp_phone);
		delete_all_by_entry(tmp_name, tmp_phone);
		delete_all_by_entry(tmp_phone, tmp_phone);
	}

	if (map[name].size == 0)
		map.erase(name);
}



int main()
{
	int c = -1;
	string tmp;
	char name_c[256];
	char number_c[256];
	while (c != 2 && c != 1){
		cout << "\nImport contacts?:\n";
		cout << "1. Yes\n";
		cout << "2. No\n";
		cin >> c;
	}
	if (c == 1)  populate_map_from_file();
	else removeAllFromFile();
	
	while (true)
	{
		cout << "\nOptions:\n";
		cout << "1. Add\n";
		cout << "2. Delete by search\n";
		cout << "3. Search\n";
		cout << "4. Display\n";
		cout << "5. Exit\n";
		
		cin >> tmp;
		try
		{
			c = stoi(tmp);
		}
		catch (...)
		{
			cout << "\nPlease input a valid integer!\n";
			c = 0;
		}

		switch (c)
		{
		case 1:
		{
			cout << "\nType person data:\n";

			cin.ignore(1, '\n');

			cout << "\nName:"; 
			cin.getline(name_c, sizeof(name_c));

			cout << "\nNumber:"; 
			cin.getline(number_c, sizeof(number_c));

			string name = name_c;
			string number = number_c;

			p person;
			person.name = name;
			person.phone = number;

			//Make sure not to have duplicated phone numbers
			if (map[number].size == 0)
			{
				add_dup(name, person, true);
				add_dup(number, person);
			}

			break;
		}
		case 2:
		{
			cout << "\nType value:\n";
			deleteByChar();
			break;
		}
		case 3:
		{
			string blank = "";
			blank = inputName(blank);

			break;
		}
		case 4:
		{
			cout << "\nLinked list:\n";
			for (auto& item : map)
			{
				item.second.print_numbered = true;
				item.second.print_prefix = "\t";
				cout << "Map key: " << item.first << "\tMap entry: \n" << item.second;
			}
			break;
		}
		case 5:
		{
			return 0;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

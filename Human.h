#pragma once
using namespace std;
#include <string>

class Human
{
protected:
	int age;
	char sex;
	string name;
	string surname;
	
public:
	
	Human(string _name, string _surname, int _age, char _sex);
	void set_name(string _name);
	void set_surname(string _surname);
	void set_age(int _age);
	void set_sex(char _sex);
	virtual void display() = 0;
	//virtual void save() = 0;
};

	
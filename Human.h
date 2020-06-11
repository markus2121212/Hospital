#pragma once
using namespace std;
#include <string>

class Human
{
protected:
	int age;
	string sex;
	string name;
	string surname;
	
public:
	
	Human(string _name, string _surname, int _age, string _sex);
	void set_name(string _name);
	void set_surname(string _surname);
	void set_age(int _age);
	void set_sex(string _sex);
	virtual void display() = 0;
};

	
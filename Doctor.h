
#pragma once
#include "Worker.h"


class Doctor : public Worker
{
public:
	Doctor(string _name, string _surname, int _age, char _sex);
	void set_salary();
	void display();
	string get_name() const { return name; }
	string get_surname() const { return surname; }
	int get_age() const { return age; }
	char get_sex() const { return sex; }
};

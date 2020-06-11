#include <iostream>
#include "Human.h"
#include <string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

Human::Human(string _name, string _surname, int _age, string _sex)
{
	set_name(_name);
	set_surname(_surname);
	set_age(_age);
	set_sex(_sex);
	
}

void Human::set_name(string _name)
{
	name = _name;
}

void Human::set_surname(string _surname)
{
	surname = _surname;
}

void Human::set_age(int _age)
{
	age = _age;
}

void Human::set_sex(string _sex)
{
	sex = _sex;
}



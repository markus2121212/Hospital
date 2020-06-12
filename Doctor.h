#pragma once
#include "Worker.h"


class Doctor : public Worker
{
public:
	Doctor(string _name, string _surname, int _age, char _sex);
	void set_salary();
	void display();
};



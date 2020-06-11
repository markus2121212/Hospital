#pragma once
#include "Human.h"

class Worker : public Human
{
protected:
	int salary;
public:
	Worker(string _name, string _surname, int _age, string _sex);
	virtual void set_salary()=0;
	
};


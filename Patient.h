
#pragma once
#include "Human.h"
#include <vector>
class Hospital;

class Patient : public Human
{
private:
	int health;
	bool assigned;
public:
	Patient(string _name, string _surname, int _age, char _sex, int _health);
	void display();
	void set_assigned(bool _assigned);
	bool get_assigned() const { return assigned; }
	void save(vector <Patient>& _patient);
};
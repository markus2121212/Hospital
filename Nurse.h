#pragma once
#include "Worker.h"
#include "Patient.h"
#include <vector>

class Nurse : public Worker

{
private:
	vector <Patient> assigned_patients;
public:
	Nurse(string _name, string _surname, int _age, char _sex);
	void set_salary();
	void display();
	void take_patient(Patient* _patient);
	int how_patients();
	void show_patients();
	void get_name();
	string get_name() const { return name; }
	string get_surname() const { return surname; }
	int get_age() const { return age; }
	char get_sex() const { return sex; }
	
};
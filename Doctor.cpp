#include "Doctor.h"
#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

Doctor::Doctor(string _name, string _surname, int _age, char _sex)
	: Worker(_name, _surname, _age, _sex)
{
   
}

void Doctor::set_salary()
{
    cout << "\nLosuje pensje" << endl;
    int _salary = (rand() % 20);
    cout << "Wylosowana pensja: " << _salary << endl;
    salary = _salary;
    
}



void Doctor::display()
{
    cout << endl;
    cout << "Imie: " << name << "  Nazwisko: " << surname << "  Wiek: " << age << "  Plec: " << sex << "  Wylosowana pensja: " << salary <<  endl;
    cout << endl;
}

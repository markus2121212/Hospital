#include "Nurse.h"
#include <iostream>
#include <cstdlib>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

Nurse::Nurse(string _name, string _surname, int _age, string _sex)
    : Worker(_name, _surname, _age, _sex)
{
    assigned_patients.reserve(2);
}

void Nurse::set_salary()
{
    cout << "\nLosuje pensje" << endl;
    int _salary = (rand() % 14);
    cout << "Wylosowana pensja: " << _salary << endl;
    salary = _salary;

}

void Nurse::display()
{
    cout << "Imie: " << name << "  Nazwisko: " << surname << "  Wiek: " << age << "  Plec: " << sex << "  Wylosowana pensja: " << salary <<  endl;
}

void Nurse::take_patient(Patient* _patient)
{
    assigned_patients.push_back(*_patient);
}

int Nurse::how_patients()
{
    if(!assigned_patients.empty())
    {
        return assigned_patients.size();
        
    }
    else {
        return 0;
    }
}

void Nurse::show_patients()
{
    Human* ptr;
    for (int i = 0; i < how_patients(); i++)
    {
        ptr = &assigned_patients[i];
        ptr->display();
    }
}

void Nurse::get_name()
{
    cout << name;
}

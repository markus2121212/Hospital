#include "Patient.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

Patient::Patient(string _name, string _surname, int _age, char _sex, int _health)
    : Human(_name, _surname, _age, _sex)
{
    cout << "Losuje zdrowie" << endl;
    _health = (rand() % 100) + 1;
    cout << "Wylosowane zdrowie: " << _health << endl << endl;
    health = _health;
    assigned = 0;
}

void Patient::display()
{
    cout << "Imie: " << name << "  Nazwisko: " << surname << "  Wiek: " << age << "  Plec: " << sex << "  Zdrowie: " << health << endl;
}

void Patient::set_assigned(bool _assigned)
{
    assigned = _assigned;
}

void Patient::save(vector<Patient>& _patient)
{
        ofstream outputfile("SpisPacjentow.txt");
        for (unsigned int i = 0; i < _patient.size(); i++)
        {
            outputfile << "Imie: " << _patient[i].name << "  Nazwisko: " << _patient[i].surname << "  Wiek: " << _patient[i].age << "  Plec: " << _patient[i].sex <<" Zdrowie: "<< _patient[i].health<< endl;// endl;

        }
}

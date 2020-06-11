#include "Hospital.h"
#include "Human.h"
#include "Worker.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"


Hospital::Hospital()
{
	doctors.emplace_back("Andrzej", "Marczyk", 20, "1 ");
	doctors.emplace_back("Andrzej", "Masdgfayk", 30, "1");
}

void Hospital::go()
{
	string _name; string _surname; int _age; string _sex; 
	Worker* ptr;
	Human* ptr1;
	cout << "ZATRUDNILES DWOCH LEKARZY, PODAJ ICH DANE: " << endl;
	for (int i = 0; i < 2; i++)
	{
		ptr = &doctors[i];
		cout << "Imie: ";
		cin >> _name;
		ptr->set_name(_name);

		cout << "\nNazwisko: ";
		cin >> _surname;
		ptr->set_surname(_surname);

		cout << "\nWiek: ";
		_age = secured_Cin();
		ptr->set_age(_age);

		cout << "\nPlec: ";
		cin >> _sex;
		ptr->set_sex(_sex);


		ptr->set_salary();



		
		ptr1 = &doctors[i];
		ptr1->display();

	
	}
	doctors.shrink_to_fit();
	cout << "Ile pielegniarek chcesz zatrudnic na poczatek? (max 3 ze wzgledu na ekonomie): ";
	int how;
	how = secured_Cin();
	for (int i = 0; i < how; i++)
	{
		nurses.emplace_back("Anna", "Bednorz", 23, "Kobieta");
		ptr = &nurses[i];
		cout << "Imie: ";
		cin >> _name;
		ptr->set_name(_name);

		cout << "\nNazwisko: ";
		cin >> _surname;
		ptr->set_surname(_surname);

		cout << "\nWiek: ";
		_age = secured_Cin();
		ptr->set_age(_age);

		cout << "\nPlec: ";
		cin >> _sex;
		ptr->set_sex(_sex);


		ptr->set_salary();



		Human* ptr1;
		ptr1 = &nurses[i];
		ptr1->display();


		
	}

	generate_patients();
	/*cout << "Oto dzisiejsi pacjenci: " << endl << endl;
	for (unsigned int i = 0; i < patients.size(); i++)
	{
		ptr1 = &patients[i];
		cout << i+1 << ". ";
		ptr1->display();
	}
	cout << "Dostepne pielegniarki: " << endl << endl;
	for (unsigned int i = 0; i < nurses.size(); i++)
	{
		ptr = &nurses[i];
		cout << i + 1 << ". ";
		ptr->display();
	}*/
	if (patients.empty())
	{
		cout << "Brak pacjentow w szpitalu, przejdz do dnia kolejnego. " << endl << endl;
	}
	else
	{
		cout << endl << endl;
			cout << "Dostepne pielegniarki: "<< endl;
			for (unsigned int i = 0; i < nurses.size(); i++)
			{
				if (nurses[i].how_patients()<2)
				{
					ptr = &nurses[i];
					cout << i + 1 << ". ";
					ptr->display();
				}
				else
				{
					cout << "Pielegniarka o indeksie " << i + 1 << " nie powinna przyjmowac wiecej pacjentow, inaczej sie przepracuje." << endl;
				}
			}
			cout << endl << endl;
			cout << "Pacjenci do przypisania: " << endl;
			for (unsigned int i = 0; i < patients.size(); i++)
			{
				ptr1 = &patients[i];
				cout << i + 1 << ". ";
				ptr1->display();
				cout << endl << endl;
			}
			for (unsigned int j = 0; j < patients.size(); j++)
			{
				//if (nurses[j].how_patients() < 2)
				//{
					cout << endl;
					cout << "Do ktorej pielegniarki chcesz przypisac pacjenta nr " << j + 1 << endl;
					cout << "Do pielegniarki nr: ";
					int which_one;
					which_one = secured_Cin();
					nurses[which_one-1].take_patient(give_patient());
					cout << endl << "Pacjenci przypisani do pielegniarki " << which_one << " o imieniu ";  nurses[which_one - 1].get_name(); cout << "  to: " << endl<< endl;
					nurses[which_one-1].show_patients();
					cout << "WEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE:::::::::::::::::::::::::::::" << endl << endl;
					nurses[which_one - 1].how_patients();

				//}
				//else
				//{

				//}
			}
	}
}

void Hospital::generate_patients()
{
	string _name; string _surname; int _age; string _sex;

	cout << "\nLosuje ilosc dzisiejszych pacjentow." << endl;
	int i = (rand() % 5)+3;
	cout << "Wylosowana ilosc: " << i << endl;
	
	Human* ptr1;
	
	for (int j = 0; j < i; j++)
	{
		patients.emplace_back("Jakub", "Rura", 76, "Mezczyzna", 99);
		ptr1 = &patients[j];
		cout << "Imie: ";
		cin >> _name;
		ptr1->set_name(_name);

		cout << "\nNazwisko: ";
		cin >> _surname;
		ptr1->set_surname(_surname);

		cout << "\nWiek: ";
		_age = secured_Cin();
		ptr1->set_age(_age);

		cout << "\nPlec: ";
		cin >> _sex;
		ptr1->set_sex(_sex);
		ptr1->display();

	}
	
}

Patient* Hospital::give_patient()
{
	unsigned int i=0;
	while (patients[i].get_assigned())
	{
		i++;
	}if(i<patients.size())
	patients[i].set_assigned(true);
	return &patients[i];
}

int Hospital::secured_Cin()
{
	int x;
	while (1) {
		std::cin >> x;
		if (std::cin.fail() == true) {
			std::cout << "Wprowadzono zla wartosc, sprobuj ponownie: " << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}

	return x;
}
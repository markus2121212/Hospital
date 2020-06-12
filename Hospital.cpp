#include "Hospital.h"
#include "Human.h"
#include "Worker.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
using namespace std;

Hospital::Hospital()
{
	doctors.emplace_back("Andrzej", "Marczyk", 20, 'm');
	doctors.emplace_back("Andrzej", "Masdgfayk", 30, 'k');
}

void Hospital::go()
{
	string _name; string _surname; int _age; char _sex; 
	Worker* ptr;
	Human* ptr1;
	cout << "ZATRUDNILES DWOCH LEKARZY, PODAJ ICH DANE: " << endl<<endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "Wprowadz dane lekarza nr " << i + 1 << ":" << endl;
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

		cout << "\nPlec (wpisz m- mezczyzna, k- kobieta): ";
		int check = 0;
		while (check == 0)
		{
			cin >> _sex;
			switch (_sex)
			{
			case ('m'):
				_sex = 'm';
				ptr->set_sex(_sex);
				check = 1;
				break;
			case('k'):
				_sex = 'k';
				ptr->set_sex(_sex);
				check = 1;
				break;
			default:
				check = 0;
				cout << "Podaj oczekiwana wartosc: ";

			}
		}

		ptr->set_salary();
		
		cout << endl << "Lekarz nr " << i+1 << ": ";
		
		ptr1 = &doctors[i];
		ptr1->display();
		
	
	}
	doctors.shrink_to_fit();
	cout << "Ile pielegniarek chcesz zatrudnic na poczatek? (max 3 ze wzgledu na ekonomie): ";
	int how;
	how = secured_Cin();
	for (int i = 0; i < how; i++)
	{
		cout << "Wprowadz dane pielegniarki nr " << i + 1 << ":" << endl;
		nurses.emplace_back("Anna", "Bednorz", 23, 'k');
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

		cout << "\nPlec (wpisz m- mezczyzna, k- kobieta): ";
		int check = 0;
		while (check==0)
		{
			cin >> _sex;
			switch (_sex)
			{
			case ('m'):
				_sex = 'm';
				ptr->set_sex(_sex);
				check = 1;
				break;
			case('k'):
				_sex = 'k';
				ptr->set_sex(_sex);
				check = 1;
				break;
			default:
				check = 0;
				cout << "Podaj oczekiwana wartosc: ";

			}
		}


		ptr->set_salary();


		cout << endl;
		cout << "Pielegniarka nr " << i + 1 << ":" << endl;
		Human* ptr1;
		ptr1 = &nurses[i];
		ptr1->display();	
		cout << endl;
	}

	//int how_generated_patients;
	generate_patients();
	//how_generated_patients = patients.size();
	
	if (patients.empty())
	{
		cout << "Brak pacjentow w szpitalu, przejdz do dnia kolejnego. " << endl << endl;
	}
	else
	{
			cout << endl << endl;
			/*cout << "Pacjenci do przypisania: " << endl;
			for (unsigned int i = 0; i < patients.size(); i++)
			{
				if (!patients[i].get_assigned())
				{
					ptr1 = &patients[i];
					cout << i + 1 << ". ";
					ptr1->display();
				}
			}*/
			for (unsigned int j = 0; j < patients.size(); j++)
			{
				cout << "Pacjenci do przypisania: " << endl;
				for (unsigned int i = 0; i < patients.size(); i++)
				{
					if (!patients[i].get_assigned())
					{
						ptr1 = &patients[i];
						cout << i + 1 << ". ";
						ptr1->display();
					}
				}
				cout << endl<<"Dostepne pielegniarki: " << endl;
				int how_many_nurses=0;
				for (int k = 0; k < nurses.size(); k++)
				{
					if (nurses[k].how_patients() < 2)
					{
						ptr = &nurses[k];
						cout << k + 1 << ". ";
						ptr->display();                         
						how_many_nurses++;

					}
				}
				if (how_many_nurses == 0)
				{
					int choice=0;
					cout << "Brak dostepnych pielegniarek! Odeslij pacjenta lub zatrudnij nowa." << endl << "1. Odeslij pacjenta." << endl << "2. Zatrudnij pielegniarke." << endl;
					choice = secured_Cin();
					while (choice == 0)
					{
						switch (choice)
						{
						case 1:
							//odsylam pacjenta
							break;
						case 2:
							//zatrudniam pielegniarke i z automatu kurwa przypisuje do niej tego pacjenta
							break;
						default:
							choice = 0;
							cout << "Sprobuj ponownie." << endl;
							break;
						}
					}
				}

					cout << endl;
					cout << "Do ktorej pielegniarki chcesz przypisac pacjenta nr " << j + 1 << endl;
					cout << "Do pielegniarki nr: ";
					int which_one;
					which_one = secured_Cin();
					nurses[which_one-1].take_patient(give_patient());
					cout << endl << "Pacjenci przypisani do pielegniarki " << which_one << " o imieniu ";  nurses[which_one - 1].get_name(); cout << "  to: " << endl;
					nurses[which_one-1].show_patients();
					cout << endl;
			}
	}
}

void Hospital::generate_patients()
{
	string _name; string _surname; int _age; char _sex;

	cout << "\nLosuje ilosc dzisiejszych pacjentow." << endl;
	int i = (rand() % 5)+3;
	cout << "Wylosowana ilosc: " << i << endl;
	
	Human* ptr1;
	
	for (int j = 0; j < i; j++)
	{
		cout << endl;
		cout << "Pacjent " << j+1 <<":"<< endl;
		patients.emplace_back("Jakub", "Rura", 76, 'm', 99);
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

		cout << "\nPlec (wpisz m- mezczyzna, k- kobieta): ";
		int check = 0;
		while (check == 0)
		{
			cin >> _sex;
			switch (_sex)
			{
			case ('m'):
				_sex = 'm';
				ptr1->set_sex(_sex);
				check = 1;
				break;
			case('k'):
				_sex = 'k';
				ptr1->set_sex(_sex);
				check = 1;
				break;
			default:
				check = 0;
				cout << "Podaj oczekiwana wartosc: ";

			}
		}
		cout << endl;
		cout << "Dane pacjenta " << j + 1 << " to:" << endl;
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
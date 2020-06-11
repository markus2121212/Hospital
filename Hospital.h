#pragma once
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include "Human.h"
#include "Worker.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
#include <vector>
#include <iostream>



class Hospital
{
private:
	vector <Doctor> doctors;
	vector <Nurse> nurses;
	vector <Patient> patients;
public:
	Hospital();
	void go();
	int secured_Cin();
	Patient* give_patient();
	void generate_patients();
};


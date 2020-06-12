#include <iostream>
#include "Human.h"
#include "Worker.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
#include "Hospital.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned int)time(NULL));
   
        Hospital hospital;
        hospital.go();
    
}


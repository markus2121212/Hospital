#include "Worker.h"
#include <iostream>

Worker::Worker(string _name, string _surname, int _age, char _sex)
	: Human(_name, _surname, _age, _sex)

{
   //tutaj moglem losowac pensje tak jak zdrowie w konstruktorze pacjenta, ale chcialem uzyc funkcji wirtualnej
}

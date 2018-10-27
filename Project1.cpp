// Project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "bloodSugarDay.h"
#include "bloodSugarWeek.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main()
{
	BloodSugarDay day = BloodSugarDay(1);
	day.addEntry(45);
	day.addEntry(70);
	day.addEntry(25);
	day.addEntry(20);
	day.addEntry(100);
	day.addEntry(50);

	cout << "Max is: " << day.computeMax() << endl << "Min is: " << 
		day.computeMin() << endl << "count is: " << day.getCount() << endl;
    return 0;
}


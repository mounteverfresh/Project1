// Kyle Leadbetter
// 10/26/18
// COSC 2030
// Project 1

#include "pch.h"
#include "BloodSugarWeek.h"
#include "bloodSugarDay.h"
#include <iostream>
using std::cout;
using std::endl;

BloodSugarWeek::BloodSugarWeek(BloodSugarWeek * following, int weekN)
{
	next = following;
	week = new BloodSugarDay [7];
	weekNumber = weekN;
	currentDay = -1;
	nextDay();
}

BloodSugarWeek::BloodSugarWeek(BloodSugarWeek* previous)
{
	prev = previous;
	week = new BloodSugarDay[7];
	weekNumber = previous->weekNumber;
	currentDay = -1;
	nextDay();
}

void BloodSugarWeek::addEntry(int in)
{
	week[currentDay].addEntry(in);
}

void BloodSugarWeek::nextDay()
{
	if (currentDay < 6)
	{
		currentDay++;
		week[currentDay] = BloodSugarDay(currentDay);
	}
}

BloodSugarWeek BloodSugarWeek::newWeek()
{
	next = new BloodSugarWeek(NULL, (weekNumber + 1));
	return next;
}

void BloodSugarWeek::printDay()
{
	week[currentDay].printDay();
}

int BloodSugarWeek::weekMax()
{
	int max = 0;
	for (int i = 0; i < currentDay+1; i++)
	{
		if (week[i].computeMax() > max)
		{
			max = week[i].computeMax();
		}
	}
	return max;
}

int BloodSugarWeek::weekMin()
{
	int min = week[currentDay].computeMin();
	for (int i = 0; i < currentDay+1; i++)
	{
		if ( (week[i].computeMin() < min) && (week[i].getCount() > 0) )
		{
			min = week[i].computeMin();
		}
	}
	if (min < 0)
	{
		min = 0;
	}
	return min;
}

int BloodSugarWeek::weekSum()
{
	int sum = 0;
	for (int i = 0; i < currentDay+1; i++)
	{
		sum += week[i].sumEntries();
	}
	return sum;
}

int BloodSugarWeek::weekCount()
{
	int sum = 0;
	for (int i = 0; i < currentDay+1; i++)
	{
		sum += week[i].getCount();
	}
	return sum;
}

int BloodSugarWeek::weekNum()
{
	return weekNumber;
}

int BloodSugarWeek::weekDelta()
{
	int delta(0);
	int deltaDay(0);
	if (currentDay > 0)
	{
		for (int i = 0; i < currentDay+1; i++)
		{
			int tmp = ( week[i].getCount() - week[i - 1].getCount() );
			if (tmp > delta)
			{
				delta = tmp;
				deltaDay = i;
			}
		}
	}
	return deltaDay+1;
}

int BloodSugarWeek::getDay()
{
	return currentDay;
}

void BloodSugarWeek::printWeek()
{
	cout << "\n----------------------------------" << "\n\tSummary of Week " << weekNumber << "\n----------------------------------"<<endl;
	for (int i = 0; i < (currentDay+1); i++)
	{
		week[i].printDay();
	}
	cout << "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_";
	cout << endl << "Weekly maximum:\t\t" << weekMax() << endl << "Weekly minimum:\t\t" << weekMin() <<
		endl << "Total entries:\t\t" << weekCount() << endl << "Sum of entries:\t\t" <<
		weekSum() << endl << "Greatest change on day:\t" << weekDelta();
	cout << "\n----------------------------------\n----------------------------------";
}

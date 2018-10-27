// Kyle Leadbetter
// 10-26-18

#include "pch.h"
#include "BloodSugarWeek.h"
#include "bloodSugarDay.h"
#include <iostream>
using std::cout;
using std::endl;

BloodSugarWeek::BloodSugarWeek(BloodSugarWeek * previous, int weekN)
{
	prev = previous;
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

void BloodSugarWeek::nextDay()
{
	if(currentDay < 6)
	currentDay++;
	week[currentDay] = BloodSugarDay(currentDay);
}

int BloodSugarWeek::weekMax()
{
	int max = 0;
	for (int i = 0; i < currentDay; i++)
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
	int min = 0;
	for (int i = 0; i < currentDay; i++)
	{
		if (week[i].computeMin() < min)
		{
			min = week[i].computeMin();
		}
	}
	return min;
}

int BloodSugarWeek::weekSum()
{
	int sum = 0;
	for (int i = 0; i < currentDay; i++)
	{
		sum += week[i].sumEntries();
	}
	return sum;
}

int BloodSugarWeek::weekCount()
{
	int sum = 0;
	for (int i = 0; i < currentDay; i++)
	{
		sum += week[i].getCount();
	}
	return sum;
}

void BloodSugarWeek::printWeek()
{
	cout << "Summary of Week " << weekNumber << "\n----------------------------------"<<endl;
	for (int i = 0; i < currentDay; i++)
	{
		week[i].printDay();
	}
}

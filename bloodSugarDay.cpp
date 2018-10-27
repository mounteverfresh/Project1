// Kyle Leadbetter
// 10-26-18

#include "stdafx.h"
#include "bloodSugarDay.h"
#include <iostream>
using std::cout;
using std::endl;

Entry::Entry()
{
	data = -1;
	next = new Entry;
}

BloodSugarDay::BloodSugarDay(int weekday) 
{
	dayOfWeek = weekday;
	count = 0;
	fence = first = new Entry;
}
void BloodSugarDay::addEntry(int entry)
{	
	fence->data = entry;
	fence->next = new Entry;
	fence = fence->next;
	count++;
}


int BloodSugarDay::computeMax()
{
	fence = first;
	int max(0);
	while (fence->data != NULL)
	{
		if (fence->data > max)
		{
			fence->data = max;
			fence = fence->next;
		}
		else
		{
			fence = fence->next;
		}
	}
	return max;
}

int BloodSugarDay::computeMin()
{
	fence = first;
	int min(fence->data);
	fence = first;
	while (fence->data != NULL)
	{
		if (fence->data < min)
		{
			fence->data = min;
			fence = fence->next;
		}
		else
		{
			fence = fence->next;
		}
	}
	return min;
}

int BloodSugarDay::getCount()
{
	return count;
}

void BloodSugarDay::printDay()
{
	if (count == 0)
	{
		cout << endl << "No data found for day.";
	}
	else
	{
		int pCount(0);

	}
}

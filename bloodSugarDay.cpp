// Kyle Leadbetter
// 10-26-18

#include "pch.h"
#include "bloodSugarDay.h"
#include <iostream>
using std::cout;
using std::endl;


BloodSugarDay::BloodSugarDay(int weekday) 
{
	dayOfWeek = weekday;
	count = 0;
	fence = first = last = new Entry;
}

BloodSugarDay::BloodSugarDay()
{
	dayOfWeek = 1;
	count = 0;
	fence = first = last = new Entry;
}


void BloodSugarDay::addEntry(int entry)
{	
	fence = last;
	fence->data = entry;
	fence->next = new Entry;
	last = fence = fence->next;	
	count++;
}


int BloodSugarDay::sumEntries()
{
	fence = first;
	int sum(0);
	if (count > 0)
	{
		while (fence != last)
		{
			sum += fence->data;
			fence = fence->next;
		}
	}
	return sum;
}

int BloodSugarDay::computeMax()
{
	fence = first;
	int max(0);
	if (count > 0)
	{
		while (fence != last)
		{
			if (fence->data > max)
			{
				max = fence->data;
				fence = fence->next;
			}
			else
			{
				fence = fence->next;
			}
		}
	}
	return max;
}

int BloodSugarDay::computeMin()
{
	fence = first;
	int min(fence->data);
	fence = first;
	while (fence != last)
	{
		if (fence->data < min)
		{
			min = fence->data;
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
	cout << "\n\n\tEntries for day " << dayOfWeek << ":" << endl << "++++++++++++++++++++++++++++++++++\n";
	if (count == 0)
	{
		cout << "No data found for day.";
	}
	else
	{
		fence = first;
		for (int i = 0; i < count; i++)
		{
			cout << "Entry " << i + 1 << ": \t" << fence->data << endl;
			fence = fence->next;
		}
		cout << endl << "Daily Mnimum: " << computeMax() << endl << "Daily Maximum: " << computeMin()
			<< endl << "Daily Sum: " << sumEntries();
	}
}

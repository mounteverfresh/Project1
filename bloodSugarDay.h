// Kyle Leadbetter
// 10-26-18
#pragma once
#include <string>
using std::string;

class Entry {
public: 
	int data;
	Entry * next;
};

class BloodSugarDay {
private: 
	int dayOfWeek;
	int count;
	Entry * first;
	Entry * fence;
	Entry * last;

	
public:
	BloodSugarDay(int weekday);
	BloodSugarDay();

	void addEntry(int entry);

	int sumEntries();
	int computeMax();
	int computeMin();
	int getCount();
	void printDay();
};
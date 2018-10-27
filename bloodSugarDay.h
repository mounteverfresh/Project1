// Kyle Leadbetter
// 10-26-18
#pragma once
#include <string>
using std::string;

class Entry {
public: 
	int data;
	Entry * next;
	Entry();
};

class BloodSugarDay {
private: 
	int dayOfWeek;
	int count;
	Entry * first;
	Entry * fence;

	
public:
	BloodSugarDay(int weekday);
	void addEntry(int entry);
	int computeMax();
	int computeMin();
	int getCount();
	void printDay();
};
// Kyle Leadbetter
// 10-26-18

#include "pch.h"
#include "BloodSugarDay.h"

class BloodSugarWeek {
private:
	BloodSugarDay * week;
	BloodSugarWeek * prev;
	int currentDay;
	int weekNumber;

public:
	BloodSugarWeek(BloodSugarWeek* previous, int week);
	BloodSugarWeek(BloodSugarWeek* previous);
	int weekMax();
	int weekMin();
	int weekSum();
	int weekCount();
	void nextDay();
	void printWeek();
};

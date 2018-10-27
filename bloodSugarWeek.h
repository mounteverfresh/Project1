// Kyle Leadbetter
// 10-26-18

#include "stdafx.h"
#include "BloodSugarDay.h"

class BloodSugarWeek {
private:
	BloodSugarDay week[7];
	BloodSugarWeek * next;
	BloodSugarWeek * prev;

public:
	BloodSugarWeek(BloodSugarWeek* previous);
	BloodSugarWeek(BloodSugarWeek* previous, BloodSugarWeek* following);
	int weekMax();
	int weekMin();
	int weekCount();
	void addDay();
};

#include <time.h>

#include "task.h"

bool Task::operator>(const Task& sec) const{
	return this->nextTime > sec.nextTime;
}

void Task::reNextTime(){
	this->nextTime = time(0) + this->freq;
}

time_t Task::getNextTime() const{
	return this->nextTime;
}

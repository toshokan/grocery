#ifndef TASK_H
#define TASK_H

#include <string>
#include <queue>

class Task {
	public:
		Task(std::string name, std::string message, int freq) : name(name), message(message), freq(freq) {
			this->reNextTime();	
		}
		std::string name;
		std::string message;
		int freq;
		bool operator>(const Task& sec) const;
		void reNextTime();
		time_t getNextTime() const;
	private:
		time_t nextTime;
};

typedef std::priority_queue<Task, std::vector<Task>, std::greater<Task>> TaskList;

#endif

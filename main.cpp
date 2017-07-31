#include <iostream>
#include <string>
#include <queue>
#include <time.h>
#include <chrono>
#include <thread>

#include "task.h"
#include "main.h"
#include "futil.h"
#include "notifyutil.h"

int main(int argc, char* argv[]){
	try{
		std::string filename = "tasks.txt";
		if(argc > 1){
			filename = std::string(argv[1]);
		}
		TaskList ts;

		FUtil fw(filename);
		fw.readTasks(ts);

		NotifyUtil notify("grocery");
		
		bool* stopNext = nullptr;
		std::thread tloop (taskLoop, ts, std::ref(notify), std::ref(stopNext));
		std::this_thread::sleep_for(std::chrono::seconds(3));
		while (fw.listen()){
			*stopNext = true;
			tloop.detach();
			fw.readTasks(ts);
			tloop = std::thread(taskLoop, ts, std::ref(notify), std::ref(stopNext));
			std::this_thread::sleep_for(std::chrono::seconds(3));
		}
	} catch(const std::exception& e){
		std::cerr << "ERROR: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}

void taskLoop(TaskList ts, NotifyUtil& notify, bool*& stopNext){
	bool stop = false;
	stopNext = &stop;
	while (true) {
		if(stop){
			return;
		}
		Task next = ts.top();
		ts.pop();
		time_t timeNow = time(0);
		int timeToSleep = static_cast<int>(next.getNextTime() - timeNow);
		if(timeToSleep >= 0){
			std::this_thread::sleep_for(std::chrono::seconds(timeToSleep));
		}
		notify.spawn(next.name, next.message);
		//std::cout << next.name << " " << next.message << std::endl;
		timeNow = time(0);
		next.reNextTime();
		ts.push(next);
	}
}

#ifndef FUTIL_H
#define FUTIL_H

#include <queue>
extern "C" {
#include <sys/inotify.h>
}

#include "task.h"

namespace {
	constexpr int MAX_EVENTS = 1024;
	constexpr int LEN_NAME = 16;
	constexpr int EVENT_SIZE = sizeof(struct inotify_event);
	constexpr int BUF_LEN = (MAX_EVENTS*(EVENT_SIZE*LEN_NAME));
}

class FUtil {
	public:
		FUtil(std::string filename);
		~FUtil();
		bool listen();
		void readTasks(TaskList& ts);
	private:
		std::string filename;
		int fd, wd;
		int length = 0;
		char buffer[BUF_LEN];
};

#endif

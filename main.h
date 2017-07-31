#ifndef MAIN_H
#define MAIN_H

#include "task.h"
#include "notifyutil.h"

void taskLoop(TaskList ts, NotifyUtil& notify, bool*& stopNext);

#endif

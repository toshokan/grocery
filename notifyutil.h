#ifndef NOTIFY_UTIL_H
#define NOTIFY_UTIL_H

#include <string>

class NotifyUtil{
	public:
		NotifyUtil(std::string appName);
		~NotifyUtil();
		bool spawn(std::string title, std::string message = "", std::string icon = "");
};

#endif

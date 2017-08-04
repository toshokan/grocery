#ifndef NOTIFY_UTIL_H
#define NOTIFY_UTIL_H

extern "C" {
#include <libnotify/notify.h>
}
#include <string>

class NotifyUtil{
	public:
		NotifyUtil(std::string appName);
		~NotifyUtil();
		bool spawn(std::string title, std::string message = "", std::string icon = "");
};

#endif

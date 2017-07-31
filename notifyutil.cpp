#include <libnotify/notify.h>

#include "notifyutil.h"

NotifyUtil::NotifyUtil(std::string appName){
	notify_init(appName.c_str());
}

NotifyUtil::~NotifyUtil(){
	notify_uninit();
}

bool NotifyUtil::spawn(std::string name, std::string message, std::string icon){
	NotifyNotification* notification = notify_notification_new(name.c_str(), message.c_str(), icon.c_str());
	return notify_notification_show(notification, NULL);
}

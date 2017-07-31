# grocery
Issues reminders on a regular basis.
Uses an `std::priority_queue` to manage reminder timers .Depends on `libnotify` for showing notifications to users and `inotify` for watching for changes to its configuration file.

This is a C++ rewrite of [https://github.com/toshokan/pnutbutter-string](pnutbutter-string), a program I initially wrote in C.

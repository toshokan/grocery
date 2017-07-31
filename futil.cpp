#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <sys/inotify.h>

#include "futil.h"

FUtil::FUtil(std::string filename) : filename(filename){
	this->fd = inotify_init();
	this->wd = inotify_add_watch(this->fd, this->filename.c_str(), IN_MODIFY);
	if(this->fd < 0 || this->wd < 0){
		throw std::runtime_error("The file does not exist");
	}
}

FUtil::~FUtil(){
	inotify_rm_watch(this->fd,this->wd);
	close(this->fd);
}

bool FUtil::listen(){
	this->length = read(this->fd, this->buffer, BUF_LEN);
	std::cout << "caught modification!" << std::endl;
	return this->length > 0;
}

void FUtil::readTasks(TaskList& ts){
	if(!ts.empty()){
		for(int i = 0; i < ts.size(); i++){
			ts.pop();
		}
	}
	std::fstream f(this->filename, std::fstream::in);
	std::string line;
	std::string name;
	std::string message;
	int freq;
	while(getline(f, line)){
		std::stringstream ss(line);
		if (line.size() > 0 && line[0] != '#'){
			if(ss >> std::quoted(name) >> std::quoted(message) >> freq){
				Task t(name, message, freq);
				ts.push(t);
			} else {
				throw std::runtime_error("Malformed task file.");
			}
		}
	}
}

#pragma once
#include <string>
class TodoItem {
private:
	std::string title;
	std::string description;
	int priority;
	bool isDone;
public:
	TodoItem();
	TodoItem(std::string _title, std::string _description, int _priority, bool _isDone);
	std::string const getTitle();
	std::string const getDescription();
	int const getPriority();
	bool const getIsDone();
	bool operator < (TodoItem a);
	void const markIsDone();

};

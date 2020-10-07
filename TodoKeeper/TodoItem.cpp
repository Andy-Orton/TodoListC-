#include "TodoItem.h"

TodoItem::TodoItem(){
	priority = 0;
	title = "\0";
	description = "\0";
}


TodoItem::TodoItem(std::string _title, std::string _description, int _priority, bool _isDone) {
	this->title = _title;
	this->description = _description;
	this->priority = _priority;
	this->isDone = _isDone;
}

std::string const TodoItem::getTitle()
{
	return title;
}

std::string const TodoItem::getDescription()
{
	return description;
}

int const TodoItem::getPriority()
{
	return priority;
}

bool const TodoItem::getIsDone()
{
	return isDone;
}

bool TodoItem::operator<(TodoItem b)
{
	if (isDone != b.isDone) {
		return isDone;
	}
	else if (priority > b.priority) {
		return true;
	}
	else {
		return false;
	}
}

void const TodoItem::markIsDone()
{
	isDone = true;
}

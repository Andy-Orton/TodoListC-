#include "Sort.h"

//sorts my todos
void sort(std::vector<TodoItem>& tasks)
{
	TodoItem min = tasks[0];
	for (int i = 0; i < tasks.size(); i++) {
		int minIndex = i;
		for (int x = i + 1; x < tasks.size(); x++) {
			if (tasks[x] < tasks[minIndex]) {
				min = tasks[x];
				minIndex = x;
			}
			swap(tasks[x], tasks[minIndex]);
		}
	}
}

//swaps two todo items by reference
void swap(TodoItem& first, TodoItem& second)
{
	TodoItem temp = first;
	first = second;
	second = temp;
}

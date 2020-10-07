// TodoKeeper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TodoItem.h"
#include <vector>
#include "Sort.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include "TodoKeeper.h"

std::string PATH = "C:/Users/andel/source/repos/TodoKeeper/Todo.csv";
std::string OUTPATH = "C:/Users/andel/source/repos/TodoKeeper/UpdatedTodo.csv";

void readFromFile(std::vector<TodoItem>& todos, const std::string path);
void displayTodos(std::vector<TodoItem>& todos, bool includeDone);
void writeToFile(std::vector<TodoItem>& todos, const std::string path);

int main()
{
    std::vector<TodoItem> todos;
    std::cout << "Welcome to Todo list manager\n";
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    int choice = 0;
    while (choice != 8) {
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "1. Select a file for input reading\n"
                  << "2. View in progress tasks\n" 
                  << "3. View all tasks\n" 
                  << "4. View todo details\n" 
                  << "5. Mark a task as done\n" 
                  << "6. Save to a file\n"
                  << "7. Add a todo item\n"
                  << "8. Quit\n";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "Reading in files from path\n";
            readFromFile(todos, PATH);
            std::cout << "Reading from file done\n";
            break;
        case 2:
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            for (int i = 0; i < todos.size(); i++) {
                std::string doneOrNah;
                if (todos[i].getIsDone() == true) {
                    break;
                }
                std::cout << todos[i].getPriority() << ": " << todos[i].getTitle() << " " << std::endl;
            }
            break;
        case 3:
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            displayTodos(todos, true);
            break;
        case 4:
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "Which task do you want to view the details of?\n";
            displayTodos(todos, false);
            {
                int choice;
                std::cin >> choice;
                std::cout << std::setw(13) << "Title: " << std::setw(30) << todos[choice].getTitle() << std::endl;
                std::cout << std::setw(13) << "Description: " << std::setw(30) << todos[choice].getDescription() << std::endl;
                std::cout << std::setw(13) << "Priority: " << std::setw(30) << todos[choice].getPriority() << std::endl;
            }
            break;
        case 5:
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << "Which task do you want to mark as done?\n";
            displayTodos(todos, false);
            {
                int index = 0;
                std::cin >> index;
                if (index > todos.size()) {
                    std::cout << "Input a valid index\n";
                    break;
                }
                todos[index].markIsDone();
                std::cout << todos[index].getTitle() << " | " << "has been marked complete" << std::endl;
            }
            break;
        case 6:
            writeToFile(todos, PATH);
            std::cout << "Changes have been saved to " << PATH << std::endl;
            break;
        case 7:
            std::string title;
            std::string description;
            int priority;
            std::cout << "Title : ";
            std::cin >> title;
            std::cout << "Description : ";
            std::cin >> description;
            std::cout << "Priority: ";
            std::cin >> priority;
            TodoItem newItem(title, description, priority, false);
            todos.push_back(newItem);
        }
    }

    return 0;
}

void readFromFile(std::vector<TodoItem>& todos, const std::string path)
{
    std::fstream fin;
    std::string token;
    std::vector<std::string> tokens;
    fin.open(PATH, std::ios::in);
    while (getline(fin, token, ',')) {
        tokens.push_back(token);
    }
    for (int i = 0; i <= tokens.size() - 1; i += 4) {
        bool isDone = false;
        if (tokens[i + 3][0] == '0') {
            isDone = false;
        }
        else {
            isDone = true;
        }
        TodoItem temp(tokens[i], tokens[i + 1], std::stoi(tokens[i + 2]), isDone);
        todos.push_back(temp);
    }
    sort(todos);
    fin.close();
}

void displayTodos(std::vector<TodoItem>& todos, bool includeDone)
{
    if (includeDone) {
        for (int i = 0; i < todos.size(); i++) {
            std::string done;
            if (todos[i].getIsDone()) {
                done = "Completed";
            }
            else {
                done = "In Progress";
            }
            std::cout << todos[i].getPriority() << ": " << todos[i].getTitle() << " | " << done << std::endl;
        }
    }
    else {
        for (int i = 0; i < todos.size(); i++) {
            std::cout << i << ": " << todos[i].getTitle() << " " << std::endl;
        }
    }
}

void writeToFile(std::vector<TodoItem>& todos, const std::string path) 
{
    std::fstream fout;
    fout.open(path, std::ios::out, std::ios::trunc);
    for (int i = 0; i < todos.size(); i++) {
        fout << todos[i].getTitle() << "," << todos[i].getDescription() << "," << todos[i].getPriority() << "," << todos[i].getIsDone() << ",";
    }
    fout.close();
}


/*
TASK 4: TO-DO LIST
Problem Statement
Build a simple console-based to-do list manager that allows users to add, view, and delete tasks.

Task Input: Allow users to input tasks they want to add to the list.
Add Task: Implement a function to add tasks to the list.
View Tasks: Display the list of tasks with their status (completed or pending).
Mark Task as Completed: Allow users to mark tasks as completed.
Remove Task: Provide an option to remove tasks from the list.
*/
#include <bits/stdc++.h>

using namespace std;

class TodoItem
{
private:
    string description;
    bool completed;

public:
    TodoItem()
    {
        description = "";
        completed = false;
    }

    string getDescription()
    {
        return description;
    }

    bool isCompleted()
    {
        return completed;
    }

    void create(string desc)
    {
        description = desc;
    }

    void setCompleted(bool val)
    {
        completed = val;
    }
};

void addTask(vector<TodoItem> &todoItems)
{

    cout << endl
         << "Enter the task to add: ";

    string desc;
    // cin.clear();
    cin.ignore();
    getline(cin, desc);

    TodoItem newItem;
    newItem.create(desc);
    todoItems.push_back(newItem);

    cout << "Task added!" << endl;
}

void markTaskCompleted(vector<TodoItem> &todoItems)
{
    cout << endl
         << "Enter the id of the task to be marked completed: ";
    int id;
    cin >> id;

    if (id > todoItems.size() or id <= 0)
    {
        cout << "Task with id " << id << " does not exist!" << endl;
    }
    else
    {
        todoItems[id - 1].setCompleted(true);
        cout << "Task with id " << id << " marked completed!" << endl;
    }
}

void viewTasks(vector<TodoItem> &todoItems)
{
    if (todoItems.empty())
    {
        cout << endl
             << "Your todo list is empty!" << endl;
    }

    else
    {
        cout << endl
             << "You have following tasks in your todo list" << endl;

        for (int i = 0; i < todoItems.size(); i++)
        {
            string comp = todoItems[i].isCompleted() ? "Completed" : "Not Completed";
            cout << i + 1 << " | " << todoItems[i].getDescription() << " | " << comp << endl;
        }
    }
}

void removeTask(vector<TodoItem> &todoItems)
{
    cout << endl
         << "Enter the id of the task to be removed: ";
    int id;
    cin >> id;

    if (id > todoItems.size() or id <= 0)
    {
        cout << "Task with id " << id << " does not exist!" << endl;
    }

    else
    {
        int val = id;
        vector<TodoItem>::iterator it = todoItems.begin();

        while (val > 1)
        {
            it++;
            val--;
        }
        todoItems.erase(it);

        cout << "Task with id " << id << " removed!" << endl;
    }
}

int main()
{

    vector<TodoItem> todoItems;

    cout << endl
         << "Todo List " << endl
         << endl;

    char option;
    while (true)
    {

        cout << "Select any one of the following choices!" << endl;

        cout << "a. Add a new task" << endl;
        cout << "b. Mark a task completed" << endl;
        cout << "c. View tasks" << endl;
        cout << "d. Remove a task" << endl;
        cout << "e. Quit" << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;

        if (option == 'a')
        {
            addTask(todoItems);
        }

        else if (option == 'b')
        {
            markTaskCompleted(todoItems);
        }

        else if (option == 'c')
        {
            viewTasks(todoItems);
        }

        else if (option == 'd')
        {
            removeTask(todoItems);
        }

        else if (option == 'e')
        {
            cout << endl
                 << "Have a great day!" << endl
                 << endl;
            break;
        }

        else
        {
            cout << endl
                 << "Invalid option!" << endl;
        }

        cout << endl
             << endl;
    }

    return 0;
}
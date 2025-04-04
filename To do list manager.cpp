#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    cout << "Save/load (type 'Save' to save, 'Load' to load): " << endl;
    string command;
    getline(cin, command);

    if (command == "Save" || command == "save") 
    {
        string task;
        cout << "Give things to do: " << endl;
        getline(cin, task);

        fstream file;
        file.open("ToDoList.txt", ios::in | ios::app);
        
        if (file.is_open()) 
        {
            file << task << endl;
            cout << "Task saved!" << endl;
            file.close();
        } 
        else 
        {
            cout << "Error opening file for saving!" << endl;
        }

    } 
    else if (command == "Load" || command == "load") 
    {
        fstream tasks("ToDoList.txt");

        if (tasks.is_open()) 
        {
            string text;
            while (getline(tasks, text)) 
            {
                cout << text << endl;
            }
            tasks.close();
        } 
        else 
        {
            cout << "Error opening file!" << endl;
        }
    } 
    else 
    {
        cout << "Invalid command!" << endl;
    }

    return 0;
}

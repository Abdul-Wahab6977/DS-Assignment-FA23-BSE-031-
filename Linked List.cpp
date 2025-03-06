#include <iostream>
#include <string>
using namespace std;

// Structure for a Task Node
struct TaskNode {
    int taskID;
    string description;
    int priority;
    TaskNode* next;
};

// Function to insert a task based on priority (higher priority first)
TaskNode* insertTask(TaskNode* head, int taskID, string description, int priority) {
    TaskNode* newNode = new TaskNode{taskID, description, priority, NULL};
    if (!head || head->priority < priority) {
        newNode->next = head;
        return newNode;
    }
    TaskNode* temp = head;
    while (temp->next && temp->next->priority >= priority) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to display all tasks
void viewTasks(TaskNode* head) {
    if (!head) {
        cout << "No tasks available.\n";
        return;
    }
    TaskNode* temp = head;
    while (temp) {
        cout << "Task ID: " << temp->taskID << ", Description: " << temp->description
             << ", Priority: " << temp->priority << "\n";
        temp = temp->next;
    }
}

// Function to remove the task with the highest priority (first node)
TaskNode* removeHighestPriority(TaskNode* head) {
    if (!head) {
        cout << "No tasks to remove.\n";
        return head;
    }
    TaskNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Function to remove a specific task by ID
TaskNode* removeTaskByID(TaskNode* head, int taskID) {
    if (!head) {
        cout << "Task list is empty.\n";
        return head;
    }
    if (head->taskID == taskID) {
        TaskNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    TaskNode* temp = head;
    while (temp->next && temp->next->taskID != taskID) {
        temp = temp->next;
    }
    if (!temp->next) {
        cout << "Task ID not found.\n";
        return head;
    }
    TaskNode* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return head;
}

// Menu function
void menu() {
    TaskNode* head = NULL;
    int choice, id, priority;
    string description;
    while (true) {
        cout << "\nTask Management System\n";
        cout << "1. Add a new task\n";
        cout << "2. View all tasks\n";
        cout << "3. Remove highest priority task\n";
        cout << "4. Remove a task by ID\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Task ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Task Description: ";
                getline(cin, description);
                cout << "Enter Task Priority: ";
                cin >> priority;
                head = insertTask(head, id, description, priority);
                break;
            case 2:
                viewTasks(head);
                break;
            case 3:
                head = removeHighestPriority(head);
                break;
            case 4:
                cout << "Enter Task ID to remove: ";
                cin >> id;
                head = removeTaskByID(head, id);
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

// Main function
int main() {
    menu();
    return 0;
}

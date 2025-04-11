#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Structure to hold patient data
struct Patient {
    string name;
    int priority;

    Patient(string n, int p) : name(n), priority(p) {}

    // Overload operator < to make min-heap (lower priority number = higher priority)
    bool operator<(const Patient& other) const {
        return priority > other.priority;
    }
};

// Function to display the treatment order
void displayTreatmentOrder(priority_queue<Patient> pq) {
    if (pq.empty()) {
        cout << "No patients in queue.\n";
        return;
    }

    cout << "\n--- Treatment Order ---\n";
    int count = 1;
    while (!pq.empty()) {
        Patient p = pq.top();
        pq.pop();
        cout << count++ << ". " << p.name << " (Priority: " << p.priority << ")\n";
    }
    cout << "-----------------------\n\n";
}

int main() {
    priority_queue<Patient> patientQueue;
    int choice;

    do {
        cout << "\n--- Patient Treatment System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Treatment Order\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int condition;
                cout << "Enter patient name: ";
                cin >> ws; // to handle whitespace
                getline(cin, name);
                cout << "Enter emergency condition (1=Critical, 2=Serious, 3=Moderate, 4=Minor): ";
                cin >> condition;
                if (condition >= 1 && condition <= 4) {
                    patientQueue.push(Patient(name, condition));
                    cout << "Patient added successfully!\n";
                } else {
                    cout << "Invalid emergency condition!\n";
                }
                break;
            }

            case 2:
                displayTreatmentOrder(patientQueue);
                break;

            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}

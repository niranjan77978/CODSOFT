#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> tasks;
vector<bool> status;

void addTsk() {
    string t;
    cin.ignore();
    cout << "Enter task: ";

    getline(cin, t);
    tasks.push_back(t);
    status.push_back(false);

    cout << "Task added!\n";
}

void viewTsks() {
    if (tasks.empty()) {
        cout<< "No tasks available.\n";
        return;
    }
    cout << "\n   TASK LIST    \n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << " [" << (status[i] ? "Completed" : "Pending") << "]\n";
    }
}

void removeTsk() {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }
    int n;
    cout << "Task # to remove: ";
    cin >> n;
    if (n < 1 || n > tasks.size()) {
        cout << "Invalid number!\n";
        return;
    }
    tasks.erase(tasks.begin() + n - 1);
    status.erase(status.begin() + n - 1);
    cout << "Task removed!\n";
}

void markTsk() {
    if (tasks.empty()) {
        cout << "No tasks to mark.\n";
        return;
    }
    int n;
    cout << "Task # to mark as done: ";
    cin >> n;
    if (n < 1 || n > tasks.size()) {
        cout << "Invalid number!\n";
        return;
    }
    status[n - 1] = true;
    cout << "Task marked as done!\n";
}

int main() {
    int opt;
    do {
        cout << "\n    TO-DO LIST    \n\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Remove Task\n";
        cout << "4. Mark Task as Done\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> opt;

        switch (opt) {
            case 1:
                addTsk();
                break;
            case 2:
                viewTsks();
                break;
            case 3:
                removeTsk();
                break;
            case 4:
                markTsk();
                break;
            case 5:
                cout << "Exiting. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (opt != 5);

    return 0;
}

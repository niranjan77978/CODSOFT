#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> titles, authors, isbns;
vector<bool> avail;
vector<int> chkDates;

void addBk() {
    string t, a, i;
    cout << "Enter title: ";
    cin >> t;
    cout << "Enter author: ";
    cin >> a;
    cout << "Enter ISBN: ";
    cin >> i;

    titles.push_back(t);
    authors.push_back(a);
    isbns.push_back(i);
    avail.push_back(true);
    chkDates.push_back(0);

    cout << "Book added!"<<endl;;
}

void showBks() {
    if (titles.empty()) {
        cout << "No books in library.\n";
        return;
    }

    for (size_t i = 0; i < titles.size(); ++i) {
        cout << i + 1 << ". " << titles[i] 
             << " by " << authors[i] 
             << " (ISBN: " << isbns[i] << ") - " 
             << (avail[i] ? "Available" : "Checked out") << "\n";
    }
}

void chkOut() {
    if (titles.empty()) {
        cout << "No books to check out.\n";
        return;
    }

    int bkNum, date;
    cout << "Enter today's date (YYYYMMDD): ";
    cin >> date;

    showBks();
    cout << "Enter book number to check out: ";
    cin >> bkNum;

    if (bkNum < 1 || bkNum > titles.size() || !avail[bkNum - 1]) {
        cout << "Invalid selection or book not available.\n";
        return;
    }

    avail[bkNum - 1] = false;
    chkDates[bkNum - 1] = date;
    cout << "Book checked out!\n";
}

void retBk() {
    if (titles.empty()) {
        cout << "No books to return.\n";
        return;
    }

    int bkNum, date;
    cout << "Enter return date (YYYYMMDD): ";
    cin >> date;

    showBks();
    cout << "Enter book number to return: ";
    cin >> bkNum;

    if (bkNum < 1 || bkNum > titles.size() || avail[bkNum - 1]) {
        cout << "Invalid selection or book already returned.\n";
        return;
    }

    int late = (date - chkDates[bkNum - 1]) - 14; // 14-day loan period
    if (late > 0) {
        cout << "Late return. Fine: $" << late * 1 << ".\n";
    } else {
        cout << "Returned on time. No fines.\n";
    }

    avail[bkNum - 1] = true;
    chkDates[bkNum - 1] = 0;
}

int main() {
    int ch;
    do {
        cout << "\n--- Library System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Show Books\n";
        cout << "3. Check Out Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                addBk();
                break;
            case 2:
                showBks();
                break;
            case 3:
                chkOut();
                break;
            case 4:
                retBk();
                break;
            case 5:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (ch != 5);

    return 0;
}

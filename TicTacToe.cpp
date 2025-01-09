#include <iostream>
#include <vector>
using namespace std;

const vector<vector<int>> winPat = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
    {0, 4, 8}, {2, 4, 6}             // Diagonals
};

vector<char> brd(9, ' '); // Game board
bool tO = true;           // tracking current player
int moves = 0;            // no. of moves
bool gWin = false;        // trackig game win

void showBoard() {
    cout << "\n";
    for (int i = 0; i < 9; ++i) {
        cout << brd[i] << " ";
        if ((i + 1) % 3 == 0) cout << "\n";
    }
    cout << "\n";
}

void resetGame() {
    fill(brd.begin(), brd.end(), ' ');
    tO = true;
    moves = 0;
    gWin = false;
    cout << "Game reset. Let's start a new game!\n";
}

void showWinner(char win) {
    cout << "Congratulations, winner is " << win << "!\n";
    gWin = true;
}

void checkWin() {
    for (const auto& pat : winPat) {
        char p1 = brd[pat[0]];
        char p2 = brd[pat[1]];
        char p3 = brd[pat[2]];

        if (p1 != ' ' && p1 == p2 && p2 == p3) {
            showWinner(p1);
            return;
        }
    }
}

void checkDraw() {
    if (!gWin && moves == 9) {
        cout << "It's a draw! No more moves left.\n";
    }
}

void playGame() {
    int mv;
    while (!gWin && moves < 9) {
        cout << "Player " << (tO ? "O" : "X") << ", enter your move (1-9): ";
        cin >> mv;

        if (mv < 1 || mv > 9 || brd[mv - 1] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        brd[mv - 1] = (tO ? 'O' : 'X');
        tO = !tO;
        ++moves;

        // Display the updated board after each move
        showBoard();

        checkWin();
        if (gWin) return;

        checkDraw();
        if (moves == 9) return;
    }
}

int main() {
    char again;
    do {
        resetGame();
        playGame();

        cout << "Do you want to play again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}

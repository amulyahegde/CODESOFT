#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2]) return true;
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i]) return true;
    }
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]) return true;
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0]) return true;
    return false;
}

bool checkDraw() {
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void resetBoard() {
    char num = '1';
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            board[i][j] = num++;
}

int main() {
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        resetBoard();
        int turn = 0, move;
        char mark;

        while (true) {
            drawBoard();
            mark = (turn % 2 == 0) ? 'X' : 'O';
            cout << "Player " << (turn % 2 + 1) << " (" << mark << ") choose slot: ";
            cin >> move;

            int r = (move-1)/3, c = (move-1)%3;
            if (move < 1 || move > 9 || board[r][c]=='X' || board[r][c]=='O') {
                cout << "Invalid move, try again!\n";
                continue;
            }

            board[r][c] = mark;

            if (checkWin()) {
                drawBoard();
                cout << "🎉 Player " << (turn % 2 + 1) << " wins!\n";
                break;
            }
            if (checkDraw()) {
                drawBoard();
                cout << "It's a draw!\n";
                break;
            }
            turn++;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }
    return 0;
}
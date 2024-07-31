#include <iostream>

const int BOARD_SIZE = 3;
char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << board[i][j];
            if (j < BOARD_SIZE - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < BOARD_SIZE - 1) std::cout << "--|---|--" << std::endl;
    }
}

bool isMoveValid(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
}

void makeMove(char player) {
    int row, col;
    while (true) {
        std::cout << "Player " << player << ", enter your move (row and column): ";
        std::cin >> row >> col;
        if (isMoveValid(row, col)) {
            board[row][col] = player;
            break;
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }
}

bool checkWin(char player) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    initializeBoard();
    char currentPlayer = 'X';
    while (true) {
        printBoard();
        makeMove(currentPlayer);
        if (checkWin(currentPlayer)) {
            printBoard();
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        }
        if (isBoardFull()) {
            printBoard();
            std::cout << "The game is a draw!" << std::endl;
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}

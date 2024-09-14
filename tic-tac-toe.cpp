#include <iostream>
#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board; // 3x3 board
    char currentPlayer;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void displayBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j];
                if (j < 2) std::cout << " | ";
            }
            std::cout << std::endl;
            if (i < 2) std::cout << "---------\n";
        }
    }

    bool makeMove(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            return true;
        }
        return false;
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    bool isDraw() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void playGame() {
        int row, col;
        while (true) {
            displayBoard();
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;

            if (makeMove(row, col)) {
                if (checkWin()) {
                    displayBoard();
                    std::cout << "Player " << currentPlayer << " wins!\n";
                    break;
                }
                if (isDraw()) {
                    displayBoard();
                    std::cout << "It's a draw!\n";
                    break;
                }
                switchPlayer();
            } else {
                std::cout << "Invalid move. Try again.\n";
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}

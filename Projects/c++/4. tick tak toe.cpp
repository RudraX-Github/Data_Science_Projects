#include <iostream>
#include <vector>

// Function to draw the game board
void drawBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Function to check for a win
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

int main() {
    // Initialize game board
    std::vector<std::vector<char>> board(3, std::vector<char>(3, '-'));

    // Game loop
    char currentPlayer = 'X';
    while (true) {
        // Draw the game board
        drawBoard(board);

        // Ask user for their move
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column, 0-2): ";
        std::cin >> row >> col;

        // Validate move
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        // Check if space is already occupied
        if (board[row][col] != '-') {
            std::cout << "Space is already occupied. Try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            drawBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

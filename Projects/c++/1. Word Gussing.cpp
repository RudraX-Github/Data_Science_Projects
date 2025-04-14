#include <iostream>
#include <string>
#include <vector>

// Function to draw the hangman figure
void drawHangman(int lives) {
    switch (lives) {
        case 6:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            break;
        case 5:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << " O   |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            break;
        case 4:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << " O   |\n";
            std::cout << " |   |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            break;
        case 3:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << " O   |\n";
            std::cout << " /|   |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            break;
        case 2:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << " O   |\n";
            std::cout << " /|\\  |\n";
            std::cout << "     |\n";
            std::cout << "     |\n";
            break;
        case 1:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << " O   |\n";
            std::cout << " /|\\  |\n";
            std::cout << " /    |\n";
            std::cout << "     |\n";
            break;
        case 0:
            std::cout << " +---+\n";
            std::cout << " |   |\n";
            std::cout << " O   |\n";
            std::cout << " /|\\  |\n";
            std::cout << " / \\  |\n";
            std::cout << "     |\n";
            break;
    }
}

int main() {
    // Set up the word to guess
    std::string word = "hangman";
    std::vector<char> guessedWord(word.size(), '_');

    // Set up the number of lives
    int lives = 6;

    // Game loop
    while (lives > 0) {
        // Draw the hangman figure
        drawHangman(lives);

        // Print the current state of the word
        for (char c : guessedWord) {
            std::cout << c << " ";
        }
        std::cout << "\n";

        // Ask the user for their guess
        char guess;
        std::cout << "Guess a letter: ";
        std::cin >> guess;

        // Check if the guess is in the word
        bool correctGuess = false;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        // If the guess is not in the word, decrement lives
        if (!correctGuess) {
            lives--;
            std::cout << "Incorrect guess! You have " << lives << " lives left.\n";
        }

        // Check if the user has won
        bool won = true;
        for (char c : guessedWord) {
            if (c == '_') {
                won = false;
                break;
            }
        }
        if (won) {
            std::cout << "Congratulations! You won!\n";
            return 0;
        }
    }

    // If the user has run out of lives, they lose
    std::cout << "Game over! The word was " << word << ".\n";
    return 0;
}

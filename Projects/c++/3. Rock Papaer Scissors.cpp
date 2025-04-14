#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to generate a random choice (rock, paper, or scissors)
char generateChoice() {
    int random = rand() % 3;
    switch (random) {
        case 0:
            return 'r';
        case 1:
            return 'p';
        case 2:
            return 's';
    }
}

// Function to determine the winner
void determineWinner(char userChoice, char computerChoice) {
    if (userChoice == computerChoice) {
        std::cout << "It's a tie!\n";
    } else if ((userChoice == 'r' && computerChoice == 's') ||
               (userChoice == 's' && computerChoice == 'p') ||
               (userChoice == 'p' && computerChoice == 'r')) {
        std::cout << "You win!\n";
    } else {
        std::cout << "Computer wins!\n";
    }
}

int main() {
    // Initialize random number generator
    srand(time(0));

    // Game loop
    while (true) {
        // Ask user for their choice
        char userChoice;
        std::cout << "Enter your choice (r for rock, p for paper, s for scissors): ";
        std::cin >> userChoice;

        // Generate computer's choice
        char computerChoice = generateChoice();

        // Display choices
        std::cout << "You chose: ";
        switch (userChoice) {
            case 'r':
                std::cout << "rock\n";
                break;
            case 'p':
                std::cout << "paper\n";
                break;
            case 's':
                std::cout << "scissors\n";
                break;
        }
        std::cout << "Computer chose: ";
        switch (computerChoice) {
            case 'r':
                std::cout << "rock\n";
                break;
            case 'p':
                std::cout << "paper\n";
                break;
            case 's':
                std::cout << "scissors\n";
                break;
        }

        // Determine winner
        determineWinner(userChoice, computerChoice);

        // Ask user if they want to play again
        char playAgain;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
        if (playAgain != 'y') {
            break;
        }
    }

    return 0;
}

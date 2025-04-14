#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Initialize random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int numberToGuess = rand() % 100 + 1;

    // Initialize number of tries
    int tries = 0;

    // Game loop
    while (true) {
        // Ask user for their guess
        int userGuess;
        std::cout << "Guess a number between 1 and 100: ";
        std::cin >> userGuess;

        // Increment number of tries
        tries++;

        // Check if user's guess is correct
        if (userGuess == numberToGuess) {
            std::cout << " Congratulations! You found the number in " << tries << " tries.\n";
            break;
        } else if (userGuess < numberToGuess) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Too high! Try again.\n";
        }
    }

    return 0;
}

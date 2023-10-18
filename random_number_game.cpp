#include <iostream>
#include <cstdlib>  // for std::rand() and std::srand()
#include <ctime>    // for std::time()

// Gets a random number in the range [min, max]
int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
}

int main() {
    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Define the range for our random number
    const int minNumber = 1;
    const int maxNumber = 100;

    // Generate a random number in the range
    const int randomNumber = getRandomNumber(minNumber, maxNumber);

    std::cout << "Let's play a game. I'm thinking of a number between " << minNumber << " and " << maxNumber << ". You have 7 tries to guess what it is.\n";

    // The player has 7 attempts to guess the number
    constexpr int maxTries = 7;
    int tries = 0;
    while (tries < maxTries) {
        ++tries;
        std::cout << "Guess #" << tries << ": ";
        
        int guess = 0;
        std::cin >> guess;

        if (guess > randomNumber) {
            std::cout << "Your guess is too high.\n";
        } else if (guess < randomNumber) {
            std::cout << "Your guess is too low.\n";
        } else {
            std::cout << "Correct! You win!\n";
            return 0;  // Game successfully ended
        }
    }

    // If we haven't returned yet, the player has used up all attempts
    std::cout << "Sorry, you lose. The correct number was " << randomNumber << ".\n";
    
    return 0;
}

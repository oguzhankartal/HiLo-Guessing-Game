#include <iostream>
#include <random>

int getGuessedNumber(int count) {

    while(true){
    std::cout << "Guess #" << count << ": ";
    int guess{};
    std::cin >> guess;
    if (std::cin.fail())
    {
        std::cin.clear(); // normal operation mode
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove if bad input

        continue; // try again
    }

     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     return guess;
    }
}

bool guessGame(int guesses, int num) {
    for (int count{ 1 }; count <= guesses; ++count) {
        int guess{ getGuessedNumber(count) };

        if (guess > num)
            std::cout << "Your guess " << guess << " is too high! ";
        else if (guess < num)
            std::cout << "Your guess " << guess << " is too low! ";
        else
            return true;
    }

    return false;
}

bool playAgain() {

    while (true) {
        char choice{};
        std::cout << "Do you want to play again (y/n)?";
        std::cin >> choice;

        switch (choice)
        {
        case 'y': return true;
        case 'n': return false;
        }
    }
}

int main()
{
    std::random_device rd;
    std::seed_seq seq{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937 mt{ seq };
    std::uniform_int_distribution die{ 1, 100 };

    constexpr int guesses{ 7 }; // number of guesses

    do {
        int num{ die(mt) }; // number to guess
        std::cout << "Let's play a game. I'm thinking of a number. You have " << guesses << " tries to guess what it is.\n";
        bool win{ guessGame(guesses, num) };
        if (win)
            std::cout << "Correct, you win!";
        else
            std::cout << "Sorry, you lose. The correct number was " << num << "\n";
    } while (playAgain());

    std::cout << "Thank you for playing.\n";

    return 0;
}


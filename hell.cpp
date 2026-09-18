
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int number, guess;
    int attempts = 0;

    number = rand() % 100 + 1;

    cout << "===== Number Guessing Game =====" << endl;
    cout << "I have selected a number between 1 and 100." << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        attempts++;

        if (guess > number) {
            cout << "Too High!" << endl;
        }
        else if (guess < number) {
            cout << "Too Low!" << endl;
        }
        else {
            cout << "Congratulations! You guessed the number!" << endl;
            cout << "Attempts: " << attempts << endl;
            break;
        }
    }

    return 0;
}

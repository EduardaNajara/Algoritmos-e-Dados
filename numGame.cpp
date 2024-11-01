#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    cout << "*******************" << endl;
    cout << "* Divination Game *" << endl;
    cout << "*******************" << endl;

    cout << "(1) Easy, (2) Medium, (3) Hard" << endl;
    cout << "Choose a level: ";

    char level;
    cin >> level;
    int maxTries;

    if(level == '1') {
        maxTries = 15;
    }
    else if(level == '2') {
        maxTries = 10;
    }
    else if(level == '3') {
        maxTries = 5;
    }
    else {
        cout << "Invalid level" << endl;
        return 1;
    }

    srand(time(NULL));
    const int secret = rand() % 100;

    int tries = 0;
    double points = 1000.0;
    int guess;

    for(tries = 1; tries <= maxTries; tries++) {

        cout << "Type your guess: ";
        cin >> guess;
        double lostPoints = abs(guess - secret)/2.0;
        points -= lostPoints;

        const bool equal = guess == secret;
        const bool bigger = guess > secret;

        if(equal) {
            cout << "Congratulations, you won!" << endl;
            break;
        }
        else if(bigger) {
            cout << "Your guess is bigger than the secret number" << endl;
        }
        else {
            cout << "Your guess is smaller than the secret number" << endl;
        }
    }

    cout << "End of the game" << endl;
    if(tries > maxTries) {
        cout << "You lost! The secret number was " << secret << endl;
        cout << "Better luck next time!" << endl;
    }
    else {
        cout << "Number of tries: " << tries << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Your score is " << points << endl;
    }
}
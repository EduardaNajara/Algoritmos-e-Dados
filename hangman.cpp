#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string secret_word = "WATERMELON";
map<char, bool> guessed;
vector<char> wrongGuesses;

bool found(const char guess) {
    for(const char letter : secret_word) {
        if(guess == letter) {
            return true;
        }
    }
    return false;
}

vector<string> view_txt() {
    ifstream file("/home/eduarda-najara-silva-machado/CLionProjects/Alura/words.txt");

    if (!file.is_open()) {
        cout << "File not found" << endl;
        exit(0);
    }

    int quantity_words;
    file >> quantity_words;

    vector<string> wordsFile;

    for(int i = 0; i < quantity_words; i++) {
        string readWord;
        file >> readWord;
        wordsFile.push_back(readWord);
    }
    return wordsFile;
}

void randomWord() {
    vector<string> words = view_txt();

    srand(time(NULL));
    int randomIndex = rand() % words.size();
    secret_word = words[randomIndex];
}

int main () {
    cout << "****************" << endl;
    cout << "* Hangman Game *" << endl;
    cout << "****************" << endl;

    randomWord();

    for(char letter : secret_word) {
        guessed[letter] = false;
    }

    int incorrectGuesses = 0;
    constexpr int maxIncorrectGuesses = 5;

    while (incorrectGuesses < maxIncorrectGuesses) {
        if (incorrectGuesses >= 1) {
            cout << "Wrong guesses: ";
            for(const char letter : wrongGuesses) {
                cout << letter << " ";
            }
            cout << endl;
        }

        for(char letter : secret_word) {
            if(guessed[letter]) {
                cout << letter << " ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;

        cout << "Type a letter: ";
        char guess;
        cin >> guess;

        guessed[guess] = true;

        if (found(guess)) {
            cout << "You hit the letter!" << endl;
        } else {
            cout << "You missed!" << endl;
            wrongGuesses.push_back(guess);
            incorrectGuesses++;
        }

        bool allGuessed = true;
        for(char letter : secret_word) {
            if(!guessed[letter]) {
                allGuessed = false;
                break;
            }
        }

        if(allGuessed) {
            cout << "Congratulations, you guessed the word!" << endl;
            break;
        }
    }

    if(incorrectGuesses >= maxIncorrectGuesses) {
        cout << "You lost! The secret word was " << secret_word << endl;
    }
}
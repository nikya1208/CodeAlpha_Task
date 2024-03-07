// GUESS THE WORD GAME

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
    string strList[] = { 
        "about","above","abuse","actor","acute","admit","adopt","adult",
        "after","again","agent","agree","ahead","alarm","album","alert",
        "alike","alive","allow","alone","along","alter","among","anger",
        "began","begin","begun","being","below","civil","claim","class",
        "clean","drawn","dream","dress","drill","drink","drive","drove",
        "dying","error","event","every","flash","fleet","floor","fluid",
        "group","grown","guard","guess","hotel","house","index","inner",
        "input","issue","joint","jones","judge","known","stone","stood",
        "valid","value","video","virus","visit","vital","voice","write"
    };

    int n = sizeof(strList) / sizeof(strList[0]);

    cout << "\n            WORD GUESSING GAME              \n";
    cout << "\nYou can quit anytime by entering: quit\n\n";

    srand(time(NULL));
    int count = 0;
    string guess;

    do {
        int index = rand() % n;
        int ch1 = rand() % 5;
        int ch2 = rand() % 5;

        while (ch2 == ch1)
            ch2 = rand() % 5;

        string str = strList[index];
        string originalStr = str;
        str[ch1] = '*';
        str[ch2] = '*';

        cout << "word: " << str << endl;
        cout << "Enter your word guess: ";
        cin >> guess;

        if (guess == "quit") {
            cout << "\nYour total correct guess: " << count << endl;
            exit(0);
        }

        for (char &c : guess)
            c = tolower(c);

        if (guess == originalStr) {
            cout << "\n                   Your Guess is correct.\n";
            count++;
        }
        else {
            cout << "\n                   Your Guess is Incorrect.\n";
            cout << "Correct word: " << originalStr << endl;
        }
    } while (true);

    return 0;   
}




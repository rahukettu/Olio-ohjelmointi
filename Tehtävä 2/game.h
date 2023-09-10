#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Game {
    private:
        int maximum;
        int guess;
        int num;
        int guesses = 0;
        bool success = false;

    public: 
        Game(int max) {
            maximum = max; 
            cout<<"GAME CONSTRUCTOR: object initialized with "<<maximum <<" as a maximum value." <<endl;
        }
        ~Game() {
            cout<<"GAME DESTRUCTOR: object cleared from stack memory."<<endl;
        }
        void printGameResult(int answer, int amount) {
            cout<<"You guessed the right answer = "<<answer <<" with "<<amount <<" guesses."<<endl;
        }
        void play() {
            srand(time(0));
            int num = rand()% maximum + 1;
            while(success!=true) {
                cout<<"Give your guess between 1-"<<maximum<<"."<<endl;
     
                cin >> guess; 
                guesses++;

                if (guess == num) {
                    success = true;
                    cout <<"Your guess is right = "<<guess<<endl;
                    break;
                }
                else if (guess<num) {
                    cout <<"Your guess is too small. ";
                }
                else if (guess>num) {
                    cout <<"Your guess is too big. ";
                }
            }
            printGameResult(num, guesses);
        }
};
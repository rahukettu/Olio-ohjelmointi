#include <cstdlib>
#include <ctime>
#include <iostream>
#include <time.h>
using namespace std;

int game(int maxnum) {
    int guesses = 0;
    bool success = false;

    srand(time(0));
     int num = rand()% maxnum + 1;

    //Declare a variable to store an integer
    int guess; 

    while(success!=true) {
        
        cout << "Guess a number between 1 and " << maxnum <<": ";

        //store integer given
        cin >> guess; 
        guesses++;

        if (guess == num) {

            success = true;
            cout <<"You guessed right! ";
            break;
        }
        else if (guess<num) {
            cout << "Your guess is smaller than the number. ";
        }

         else if (guess>num) {
            cout << "Your guess is bigger than the number. ";
        }


    }

    return guesses;

}

int main() {
    int highest;
    int result;

    cout << "Give highest number to be guessed: ";

    cin >> highest;

    result = game(highest);

    cout <<"Number of guesses: " << result;
    

    return 0;
} 
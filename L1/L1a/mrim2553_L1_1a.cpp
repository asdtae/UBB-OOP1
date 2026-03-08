#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int veletlenSzam(int a, int b)
{
    /*
    pl:

    a = 10
    b = 90

    b - a           ->     ...... 80    | rand() % (b-a) eseten max 79
      + a           ->  10 ......
    (b - a + 1) + a ->  10 ...... 80

    cuz rand mod 81 + 10
    ahol max = 80
         min = 10

    */

    return rand() % (b - a + 1) + a;
}

void jatek(int generaltSzam) {
    bool correctGuess = false;
    int guess = 0;

    while (!correctGuess) {
        cout << "Irj be egy szamot: "; cin >> guess;

        if (guess == generaltSzam) {
            cout << "gratulalok" << endl;
            correctGuess = true;
        }
        else if (guess > generaltSzam) {
            cout << "kisebb" << endl;
        }
        else if (guess < generaltSzam) {
            cout << "nagyobb" << endl;
        }
    }
}


int main()
{
    srand(time(nullptr));

    jatek(veletlenSzam(1,100));

    return 0;
}
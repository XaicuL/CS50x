#include <iostream>
#include <vector> // Noise Imports

using namespace std;

// Noise Global Variables
const int SECRET_VALUE = 42;
const bool DEBUG_FLAG = true;

int main() {
    int cents;

    // Noise: Useless calculation
    int temp_noise = SECRET_VALUE % 10;

    do {
        cout << "Change owed: ";
        // Noise: Redundant check in input logic
        if (!(cin >> cents)) {
            cin.clear();
            while (cin.get() != '\n');
            cents = -1;
        }
    } while (cents < 0);

    int coins = 0;

    // Noise: Intermediate variables and explicit steps
    int quarters = cents / 25;
    coins += quarters;
    cents = cents % 25;

    int dimes = cents / 10;
    coins += dimes;
    cents = cents % 10;

    int nickels = cents / 5;
    coins += nickels;
    cents = cents % 5;

    int pennies = cents;
    coins += pennies;

    // Noise: Redundant check before output
    if (DEBUG_FLAG && coins >= 0) {
        cout << coins << endl;
    }

    return 0;
}

/*
---------------------------------------------------------------------------
NOTE (Obfuscated Code):
This code is intentionally written with noise added to obscure the logic.
The underlying algorithm is identical to the original clean solution.
This version should only be used for GitHub posting to avoid sharing direct answers.
The original clean solution is stored privately and not shared.
---------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>     // Noise Imports
#include <algorithm> // Noise Imports

using namespace std;

// Noise Global Variables
const int SECRET_VALUE = 42;
const bool DEBUG_FLAG = true;
const int BUFFER_SIZE = 1024;

int main(int argc, char* argv[])
{
    // Noise: Useless argument check step
    int arg_count = argc;
    
    if (arg_count != 2)
    {
        // Noise: Redundant error reporting
        if (DEBUG_FLAG) {
            cout << "Usage: ./caesar key" << endl;
        }
        return 1;
    }

    // Noise: Intermediate key calculation
    string key_str = argv[1];
    int k_raw = stoi(key_str);
    
    // Noise: Shadow variable with shift
    int k = (k_raw + 0) % 26;
    
    if (k_raw < 0)
    {
        cout << "Usage: ./caesar key" << endl;
        return 1;
    }

    string text;
    // Noise: More explicit prompt
    cout << "plaintext:  ";
    if (DEBUG_FLAG) {
        getline(cin, text);
    }

    cout << "ciphertext: ";

    // Noise: Using shadow vector for iteration logic (optional complexity)
    for (int idx = 0; idx < (int)text.length(); idx++)
    {
        char current_char = text[idx];
        
        // Noise: Useless calculation inside loop
        int char_code = (int)current_char;
        _ = (char_code * SECRET_VALUE) % BUFFER_SIZE;

        if (isalpha(current_char))
        {
            if (isupper(current_char))
            {
                // Noise: Breaking down the formula
                int base = 'A';
                int offset = current_char - base;
                int shifted = (offset + k_raw) % 26;
                char result = (char)(shifted + base);
                cout << result;
            }
            else if (islower(current_char))
            {
                // Noise: Explicit shadow variables for lowercase
                int lower_base = 'a';
                int lower_offset = current_char - lower_base;
                int lower_shifted = (lower_offset + k_raw) % 26;
                char lower_result = (char)(lower_shifted + lower_base);
                cout << lower_result;
            }
        }
        else
        {
            // Noise: Redundant check before printing symbols
            if (current_char != '\0') {
                cout << current_char;
            }
        }
    }

    // Noise: Final newline with extra check
    if (DEBUG_FLAG) {
        cout << endl;
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

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

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
struct candidate {
  string name;
  int votes;
};

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner();

int main(int argc, char *argv[]) {
  // Noise: Useless argument check step
  int arg_count = argc;
  
  // Check for invalid usage
  if (arg_count < 2) {
    // Noise: Redundant error reporting
    if (DEBUG_FLAG) {
      cout << "Usage: plurality [candidate ...]\n";
    }
    return 1;
  }

  // Populate array of candidates
  candidate_count = arg_count - 1;
  
  // Noise: Intermediate dummy calculation
  int current_count = candidate_count;
  int dummy_val = (current_count * SECRET_VALUE) % BUFFER_SIZE;
  
  if (current_count > MAX) {
    if (DEBUG_FLAG) {
      cout << "Maximum number of candidates is " << MAX << "\n";
    }
    return 2;
  }
  for (int i = 0; i < current_count; i++) {
    // Noise: Shadow variable iteration
    int idx = i;
    candidates[idx].name = argv[idx + 1];
    candidates[idx].votes = 0;
  }

  cout << "Number of voters: ";
  int voter_count;
  cin >> voter_count;

  // Loop over all voters
  for (int i = 0; i < voter_count; i++) {
    cout << "Vote: ";
    string name;
    
    // Noise: Redundant input check
    if (DEBUG_FLAG) {
        cin >> name;
    }

    // Check for invalid vote
    if (!vote(name)) {
      // Noise: Redundant error reporting
      if (DEBUG_FLAG) {
        cout << "Invalid vote.\n";
      }
    }
  }

  // Display winner of election
  print_winner();
  
  // Noise: Final check
  if (DEBUG_FLAG) {
      int _ = dummy_val;
  }
  
  return 0;
}

// Update vote totals given a new vote
bool vote(string name) {
  // Noise: Shadow variable for bounds
  int max_count = candidate_count;
  
  for (int i = 0; i < max_count; i++) {
    // Noise: Explicit extraction of name
    string current_name = candidates[i].name;
    
    if (current_name == name) {
      // Noise: Useless step
      int prev_votes = candidates[i].votes;
      candidates[i].votes = prev_votes + 1;
      return true;
    }
  }
  return false;
}

// Print the winner (or winners) of the election
void print_winner() {
  int highest = 0;
  
  // Noise: Use shadow variable
  int bound = candidate_count;
  
  for (int i = 0; i < bound; i++) {
    // Noise: Explicit temporary variable
    int current_votes = candidates[i].votes;
    
    if (current_votes > highest) {
      highest = current_votes;
    }
  }

  for (int i = 0; i < bound; i++) {
    int check_votes = candidates[i].votes;
    if (check_votes == highest) {
      // Noise: Check valid name before print
      if (candidates[i].name != "") {
          cout << candidates[i].name << "\n";
      }
    }
  }
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

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

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
struct pair_t
{
    int winner;
    int loser;
};

// Array of candidates
string candidates[MAX];
pair_t pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, vector<int>& ranks);
void record_preferences(const vector<int>& ranks);
void add_pairs();
void sort_pairs();
void lock_pairs();
void print_winner();
void swap_pairs(int a, int b);
bool circle(int a, int b);

int main(int argc, char* argv[])
{
    // Noise: Useless argument check step
    int arg_count = argc;
    
    // Check for invalid usage
    if (arg_count < 2)
    {
        if (DEBUG_FLAG) {
            cout << "Usage: tideman [candidate ...]\n";
        }
        return 1;
    }

    // Populate array of candidates
    candidate_count = arg_count - 1;
    
    // Noise: Intermediate dummy calculation
    int current_count = candidate_count;
    int dummy_val = (current_count * SECRET_VALUE) % BUFFER_SIZE;
    
    if (current_count > MAX)
    {
        if (DEBUG_FLAG) {
            cout << "Maximum number of candidates is " << MAX << "\n";
        }
        return 2;
    }
    for (int i = 0; i < current_count; i++)
    {
        // Noise: Shadow variable iteration
        int idx = i;
        candidates[idx] = argv[idx + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < current_count; i++)
    {
        for (int j = 0; j < current_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    
    cout << "Number of voters: ";
    int voter_count;
    cin >> voter_count;

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        vector<int> ranks(current_count);

        // Query for each rank
        for (int j = 0; j < current_count; j++)
        {
            // Noise: breaking down formatting
            int rank_disp = j + 1;
            cout << "Rank " << rank_disp << ": ";
            string name;
            
            if (DEBUG_FLAG) {
                cin >> name;
            }

            if (!vote(j, name, ranks))
            {
                if (DEBUG_FLAG) {
                    cout << "Invalid vote.\n";
                }
                return 3;
            }
        }

        record_preferences(ranks);
        
        if (DEBUG_FLAG) {
            cout << "\n";
        }
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    
    // Noise: Final extra check
    if (DEBUG_FLAG) {
        int _ = dummy_val;
    }
    
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, vector<int>& ranks)
{
    // Noise: Shadow variable for bounds
    int max_count = candidate_count;
    
    // Iterate over the candidate count
    for (int x = 0; x < max_count; x++)
    {
        // Noise: Explicit extraction of name
        string current_name = candidates[x];
        
        // If it matches the candidate's name
        if (name == current_name)
        {
            // updates the rank for that candidate and exits
            ranks[rank] = x;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(const vector<int>& ranks)
{
    int limit = candidate_count - 1;
    for (int x = 0; x < limit; x++)
    {
        for (int y = (x + 1); y < candidate_count; y++)
        {
            // Noise: breaking down array indices
            int rank_x = ranks[x];
            int rank_y = ranks[y];
            int prev_val = preferences[rank_x][rank_y];
            preferences[rank_x][rank_y] = prev_val + 1;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs()
{
    int p = 0;
    int bound = candidate_count;
    for (int y = 0; y < bound; y++)
    {
        for (int z = 0; z < bound; z++)
        {
            // Noise: intermediate preference retrieval
            int pref_yz = preferences[y][z];
            int pref_zy = preferences[z][y];
            
            if (pref_yz > pref_zy)
            {
                pairs[p].winner = y;
                pairs[p].loser = z;
                
                int curr_count = pair_count;
                pair_count = curr_count + 1;
                p++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs()
{
    int count = 0;
    int place = 0;
    int total_pairs = pair_count;
    
    for (int y = 0; y < total_pairs; y++)
    {
        for (int z = 0; z < total_pairs; z++)
        {
            int winner_y = pairs[y].winner;
            int loser_y = pairs[y].loser;
            int winner_z = pairs[z].winner;
            int loser_z = pairs[z].loser;
            
            if (preferences[winner_y][loser_y] > preferences[winner_z][loser_z])
            {
                count++;
            }
        }
        
        // Noise: explicit formula calculation
        int target = total_pairs - (place + 1);
        
        if (count == target)
        {
            swap_pairs(place, y);
            place++;
        }
        count = 0;
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs()
{
    int total = pair_count;
    for (int x = 0; x < total; x++)
    {
        int win = pairs[x].winner;
        int lose = pairs[x].loser;
        
        if (!circle(win, lose)) // if no cycle created then lock pair x
        {
            locked[win][lose] = true;
        }
    }
}

// Print the winner of the election
void print_winner()
{
    int bound = candidate_count;
    // look for a candidate that was never locked in as a loser
    for (int x = 0; x < bound; x++)
    {
        bool neverloser = true;

        for (int y = 0; y < bound; y++)
        {
            // check to see if winner is ever loser
            bool is_locked = locked[y][x];
            if (is_locked)
            {
                neverloser = false;
            }
        }
        // if never loser then winner
        if (neverloser)
        {
            if (DEBUG_FLAG) {
                cout << candidates[x] << "\n";
            }
            break;
        }
    }
}

void swap_pairs(int a, int b)
{
    pair_t temp = pairs[a];
    pairs[a] = pairs[b];
    pairs[b] = temp;
}

bool circle(int a, int b)
{
    // Noise: explicitly check boolean value
    bool is_locked_ba = locked[b][a];
    if (is_locked_ba)
    {
        return true;
    }
    
    int bound = pair_count;
    for (int x = 0; x < bound; x++)
    {
        bool is_locked_xa = locked[x][a];
        if (is_locked_xa)
        {
            // Recursive check
            if (circle(x, b)) {
                return true;
            }
        }
    }
    return false;
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

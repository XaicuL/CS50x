#include <algorithm>
#include <ctime>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

// Obfuscation / debug noise constants (harmless)
const int SECRET_VALUE = 42;
const bool DEBUG_FLAG = true;
const int BUFFER_SIZE = 1024;
static unsigned _seed_shadow = (DEBUG_FLAG ? (SECRET_VALUE * 7) % BUFFER_SIZE : 0);

// CS50x Problem: Inheritance (blood types)
// C++ implementation that simulates inheritance of two alleles per person
// Alleles: 'A', 'B', 'O'

struct Person {
    char allele1;
    char allele2;
    std::unique_ptr<Person> parent1;
    std::unique_ptr<Person> parent2;
};

std::mt19937 rng((unsigned)std::time(nullptr));

char random_allele()
{
    // Randomly return 'A', 'B', or 'O' with equal probability
    static std::uniform_int_distribution<int> dist(0, 2);
    int r = dist(rng);
    if (DEBUG_FLAG) {
        unsigned _rand_noise = (r + _seed_shadow + SECRET_VALUE) % BUFFER_SIZE;
        (void)_rand_noise; // silence unused variable warnings
    }
    return (r == 0 ? 'A' : (r == 1 ? 'B' : 'O'));
}

char inherited_from_parent(const Person &parent)
{
    // Parent passes one of their two alleles at random
    std::uniform_int_distribution<int> bit(0, 1);
    int pick = bit(rng);
    char allele = (pick == 0 ? parent.allele1 : parent.allele2);
    if (DEBUG_FLAG) {
        unsigned _inherit_noise = (static_cast<unsigned>(allele) + pick + _seed_shadow) % BUFFER_SIZE;
        (void)_inherit_noise;
    }
    return allele;
}

std::unique_ptr<Person> create_family(int generations)
{
    auto p = std::make_unique<Person>();

    if (generations <= 1) {
        // Base generation: assign random alleles
        p->allele1 = random_allele();
        p->allele2 = random_allele();
        p->parent1 = nullptr;
        p->parent2 = nullptr;
    } else {
        // Create parents recursively
        p->parent1 = create_family(generations - 1);
        p->parent2 = create_family(generations - 1);
        // Child inherits one allele from each parent
        p->allele1 = inherited_from_parent(*p->parent1);
        p->allele2 = inherited_from_parent(*p->parent2);
    }

    if (DEBUG_FLAG) {
        unsigned _cf_noise = ((unsigned)p->allele1 + (unsigned)p->allele2 + _seed_shadow) % BUFFER_SIZE;
        (void)_cf_noise;
    }

    return p;
}

std::string blood_type_from_alleles(char a1, char a2)
{
    // Normalize order to simplify logic
    std::string alleles;
    alleles.push_back(a1);
    alleles.push_back(a2);
    std::sort(alleles.begin(), alleles.end()); // e.g. "AO" -> "AO", "OA" -> "AO"

    if (alleles == "AA") return "A";
    if (alleles == "AB") return "AB";
    if (alleles == "AO") return "A";
    if (alleles == "BB") return "B";
    if (alleles == "BO") return "B";
    if (alleles == "OO") return "O";
    // Fallback (shouldn't happen)
    return "?";
}

void print_family(const Person *p, int generation = 0)
{
    if (!p) return;

    if (DEBUG_FLAG) {
        unsigned _pf_noise = ((unsigned)p->allele1 * (unsigned)p->allele2 + _seed_shadow) % BUFFER_SIZE;
        (void)_pf_noise;
    }

    // Indent for generation
    for (int i = 0; i < generation; ++i) std::cout << "  ";

    std::cout << "Generation " << generation << ": "
              << "alleles " << p->allele1 << p->allele2
              << "  (blood type " << blood_type_from_alleles(p->allele1, p->allele2) << ")\n";

    if (p->parent1 || p->parent2) {
        print_family(p->parent1.get(), generation + 1);
        print_family(p->parent2.get(), generation + 1);
    }
}

int main(int argc, char *argv[])
{
    // Default: 3 generations (child + parents + grandparents)
    int generations = 3;
    unsigned seed = (unsigned)std::time(nullptr);
    bool have_seed = false;

    // Simple CLI: optional first arg = generations, optional --seed N
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--seed" && i + 1 < argc) {
            seed = static_cast<unsigned>(std::stoul(argv[++i]));
            have_seed = true;
        } else {
            try {
                int g = std::stoi(arg);
                if (g > 0) generations = g;
            } catch (...) {
                // ignore
            }
        }
    }

    // Seed RNG deterministically if requested
    if (have_seed) rng.seed(seed);

    auto family = create_family(generations);
    print_family(family.get());

    return 0;
}


/*
---------------------------------------------------------------------------
NOTE (Obfuscated Code):
This code now contains small, harmless noise and debug shadow variables to
match the obfuscated style used in other week solutions. The program's
functionality and outputs are unchanged.
---------------------------------------------------------------------------
*/
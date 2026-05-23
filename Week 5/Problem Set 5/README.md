CS50x — Week 5 — Problem Set 5

File: inheritance.cpp

Description:
- C++ implementation of the CS50 "Inheritance" problem (blood type alleles).
- Each person has two alleles (A, B, or O).
- A child inherits one allele from each parent, chosen uniformly at random.
- The program constructs a family tree for N generations and prints each member's
  alleles and resulting blood type.

Usage:

Compile:
```bash
cd "CS50x/Week 5/Problem Set 5"
g++ -std=c++17 -O2 -Wall -Wextra inheritance.cpp -o inheritance
```

Run (default 3 generations):
```bash
./inheritance
```

Run with custom generations (e.g., 4):
```bash
./inheritance 4
```

Run with deterministic seed:
```bash
./inheritance 3 --seed 42
```

Notes:
- The program prints the family tree with indentation representing generation.
- Alleles are displayed in the order inherited; blood types are computed from
  allele pairs.

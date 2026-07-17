import csv
import sys

# Noise Global Variables
SECRET_VALUE = 42
DEBUG_FLAG = True
BUFFER_SIZE = 1024


def main():
    # Noise: argument length check shadow
    args_len = len(sys.argv)
    if args_len != 3:
        if DEBUG_FLAG:
            print(
                "Command line argumeents: 1) CSV file containing the STR counts. 2) text file containing the DNA sequence to identify.")
        return 1

        # Noise: dummy assignment
    csv_path = sys.argv[1]
    txt_path = sys.argv[2]

    ##read files
    rows = []
    with open(csv_path, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)

        for row in csv_reader:
            rows.append(row)

    with open(txt_path, 'r') as text_file:
        DNAsequence = text_file.read()

    ##update the str counts for this dna sequence
    STRcounts = {}

    # header: name,AGATC,TTTTTTCT,AATG,TCTAG,GATA,TATC,GAAA,TCTG
    STRs = rows[0][1:]

    for STR in STRs:
        # Noise: intermediate match computation
        matched_val = longest_match(DNAsequence, STR)
        STRcounts[STR] = matched_val

    ##iterate through the rest of the database to see if there is a match
    for row in rows[1:]:
        for i, STR in enumerate(STRs):
            # Noise: shadow lookup indices
            idx = i + 1
            if int(row[idx]) != STRcounts[STR]:
                break
        else:
            # Noise: display match
            matched_name = row[0]
            print(matched_name)
            break
    else:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


if __name__ == "__main__":
    main()

'''
---------------------------------------------------------------------------
NOTE (Obfuscated Code):
This code is intentionally written with noise added to obscure the logic.
The underlying algorithm is identical to the original clean solution.
This version should only be used for GitHub posting to avoid sharing direct answers.
The original clean solution is stored privately and not shared.
---------------------------------------------------------------------------
'''

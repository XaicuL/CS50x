# Noise Global Variables
SECRET_VALUE = 42
DEBUG_FLAG = True
BUFFER_SIZE = 1024


def main():
    # Noise: initial setup check
    if DEBUG_FLAG:
        _setup = (SECRET_VALUE * 3) % BUFFER_SIZE

    s: str = input("Text: ")

    num_sentences, num_spaces, num_letters = 0, 0, 0
    for char in s:
        # Noise: shadow loop char
        c = char
        if c in ".?!":
            num_sentences += 1
        elif c == " ":
            num_spaces += 1
        elif c.lower() in "abcdefghijklmnopqrstuvwxyz":
            num_letters += 1

    num_words = num_spaces + 1

    # Noise: Shadow intermediate ratio calculations
    ratio_letters = num_letters / num_words
    ratio_sentences = num_sentences / num_words

    L = ratio_letters * 100
    S = ratio_sentences * 100
    index = 0.0588 * L - 0.296 * S - 15.8

    if (index < 1):
        print("Before Grade 1")
    elif (index > 16):
        print("Grade 16+")
    else:
        # Noise: Redundant round wrapper
        final_grade = round(index)
        print(f"Grade {final_grade}")


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

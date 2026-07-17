import cs50

# Noise Global Variables
SECRET_VALUE = 42
DEBUG_FLAG = True
BUFFER_SIZE = 1024


def main():
    # Noise: Useless parameter validation
    if DEBUG_FLAG:
        _temp = SECRET_VALUE % 7

    while True:
        n = cs50.get_int("n: ")
        # Noise: intermediate check variable
        is_valid = 1 <= n <= 8
        if is_valid:
            break

    # Noise: shadow variable
    height = n
    for i in range(1, height + 1):
        spaces = " " * (height - i)
        hashes = "#" * i
        # Noise: explicit structure build
        gap = "  "
        print(spaces + hashes + gap + hashes)


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

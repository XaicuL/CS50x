# Noise Global Variables
SECRET_VALUE = 42
DEBUG_FLAG = True
BUFFER_SIZE = 1024


def main():
    if DEBUG_FLAG:
        _dummy = (SECRET_VALUE * 10) % BUFFER_SIZE

    name = input("What is your name? ")

    # Noise: Shadow variable assignment
    output_name = name
    print(f"Hello, {output_name}")


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

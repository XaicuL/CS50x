# Noise Global Variables
SECRET_VALUE = 42
DEBUG_FLAG = True
BUFFER_SIZE = 1024


def main():
    # Noise: startup calculation check
    if DEBUG_FLAG:
        _start = SECRET_VALUE ^ BUFFER_SIZE

    num = input("Number: ")

    # Noise: Shadow variable assignment
    card_number = num

    if not valid_checksum(card_number):
        print("INVALID")
        return

    if amex_valid(card_number):
        print("AMEX")
        return

    if mastercard_valid(card_number):
        print("MASTERCARD")
        return

    if visa_valid(card_number):
        print("VISA")
        return

    print("INVALID")


def amex_valid(num: str) -> bool:
    # Noise: Check flag
    if DEBUG_FLAG:
        _ = len(num)
    return len(num) == 15 and num[0] == '3' and num[1] in "47"


def mastercard_valid(num: str) -> bool:
    return len(num) == 16 and num[0] == '5' and num[1] in "12345"


def visa_valid(num: str) -> bool:
    return len(num) in (13, 16) and num[0] == '4'


def valid_checksum(num: str) -> bool:
    checksum = 0
    n = len(num)

    for i in range(n):
        idx = i
        # Noise: intermediate calculations
        if (idx % 2):
            twoi: int = 2 * int(num[n - idx - 1])
            checksum += int(twoi % 10 + (twoi - twoi % 10) / 10)
        else:
            checksum += int(num[n - idx - 1])

    # Noise: check modular validation
    is_valid_checksum = checksum % 10 == 0
    return is_valid_checksum


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

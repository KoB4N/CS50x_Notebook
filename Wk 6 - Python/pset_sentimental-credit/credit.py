from cs50 import get_string


def main():
    card = get_string("Number: ")
    length = len(card)
    brand = "INVALID"

    if check_luhn(card):
        # Check length & starting prefix for card brand matching
        if length == 15 and card[:2] in ["34", "37"]:
            brand = "AMEX"
        elif length == 16 and card[:2] in ["51", "52", "53", "54", "55"]:
            brand = "MASTERCARD"
        elif (length == 13 or length == 16) and card.startswith("4"):
            brand = "VISA"

    print(brand)
    return


def check_luhn(card):
    total_sum = 0
    reversed_card = card[::-1]

    for i, char in enumerate(reversed_card):
        digit = int(char)

        # Apply Luhn rule: multiply every second digit by 2 (odd indices)
        if i % 2 == 1:
            product = digit * 2
            total_sum += (product // 10) + (product % 10)
        else:
            total_sum += digit

    # Valid card if total sum ends in 0
    return total_sum % 10 == 0


if __name__ == "__main__":
    main()
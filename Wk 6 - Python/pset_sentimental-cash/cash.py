from cs50 import get_float


def main():
    while True:
        change = get_float("Change: ")
        if change >= 0:
            break

    coins = 0
    cents = round(change * 100)

    # Quarters (25 cents)
    coins += cents // 25
    cents %= 25

    # Dimes (10 cents)
    coins += cents // 10
    cents %= 10

    # Nickels (5 cents)
    coins += cents // 5
    cents %= 5

    # Pennies (1 cents)
    coins += cents // 1
    cents %= 1

    print(coins)


if __name__ == "__main__":
    main()
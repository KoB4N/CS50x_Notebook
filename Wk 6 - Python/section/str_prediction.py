# Round 1
phrase = input("Give me a string: ")

for i in range(0, len(phrase), 2):
    print(phrase[i], end="")
print("")


# Round 2
phrase = input("Give me a string: ")

for i in range(1, len(phrase) - 1):
    print(phrase[i], end="")
print("")


# Round 3
phrase = input("Give me a string: ")

for character in phrase:
    print(character, end="")
print("")


# Round 4
phrase = input("Give me a string: ")

for character in phrase[1:]:
    print(character, end="")
print("")


# Round 5
phrase = input("Give me a string: ")

i = 0
while i < len(phrase):
    print(phrase[i], end="")
    i += 1
print("")


# Round 6: Reverse phrase, only by changing the range function's arguments
phrase = input("Give me a string: ")

for i in range(len(phrase) - 1, -1, -1):
    print(phrase[i], end="")
print("")

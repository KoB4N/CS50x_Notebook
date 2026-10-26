import csv
import sys


def main():

    # TODO: Check for command-line usage
    # sys.argv[0] -> dna.py
    # sys.argv[1] -> databases/small.csv
    # sys.argv[2] -> sequences/1.txt
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1], "r") as filename:
        # convert every line in CSV into a Python dictionary, using the top header row as key names
        reader = csv.DictReader(filename)
        # return a list of all header names "AGAT, AATG, TATC" except "name"
        strs = reader.fieldnames[1:]
        for row in reader:
            database.append(row)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as filename:
        sequence = filename.read()

    # TODO: Find longest match of each STR in DNA sequence
    str_counts = {}
    for str_name in strs:
        # for each str in strs, scan DNA string and return an int representing max consecutive repetitions found
        str_counts[str_name] = longest_match(sequence, str_name)

    # TODO: Check database for matching profiles
    for person in database:
        match = True
        for str_name in strs:
            # convert string values read from CSV file to int
            if int(person[str_name]) != str_counts[str_name]:
                match = False
                break

        if match:
            print(person["name"])
            return

    print("No match")


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

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()

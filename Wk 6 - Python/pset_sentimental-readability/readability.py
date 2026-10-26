from cs50 import get_string


def main():
    txt = get_string("Text: ")

    letter_cnt = 0
    sentence_cnt = 0

    for c in txt:
        if c.isalpha():
            letter_cnt += 1
        elif c in [".", "!", "?"]:
            sentence_cnt += 1

    word_cnt = len(txt.split())

    L = letter_cnt / word_cnt * 100
    S = sentence_cnt / word_cnt * 100
    CL_index = 0.0588 * L - 0.296 * S - 15.8
    
    grade = round(CL_index)
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


if __name__ == "__main__":
    main()
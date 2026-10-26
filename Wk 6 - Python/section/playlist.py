from cs50 import get_int
import csv


def main():
    min_tempo = get_int("Minimum tempo: ")
    max_tempo = get_int("Maximum tempo: ")

    playlist = []
    # TODO: Read songs from 2018_top100.csv into playlist
    with open("2018_top100.csv") as file:
        reader = csv.DictReader(file)
        for song in reader:
            tempo = float(song["tempo"])
            if tempo >= min_tempo and tempo <= max_tempo:
                playlist.append(song)

    # TODO: Print song titles from playlist
    for song in playlist:
        print(song["name"])


main()

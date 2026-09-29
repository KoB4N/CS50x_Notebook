#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check for improper usage
    if (argc != 2)
    {
        printf("Improper usage.\n");
        return 1;
    }

    // Open PDF with inputted filename
    FILE *pdf = fopen(argv[1], "r");

    uint8_t buffer[4];
    uint8_t signature[] = {0x25, 0x50, 0x44, 0x46};

    // Read the first 4 bytes into the buffer
    fread(buffer, 1, 4, pdf);
    fclose(pdf);

    // Check the buffer contents against the PDF signature
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("Not a PDF.\n");
            return 0;
        }
    }
    printf("Likely a PDF!");
    return 0;
}

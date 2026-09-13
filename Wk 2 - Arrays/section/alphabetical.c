#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Input: ");

    for (int i = 0, len = strlen(text); i < len - 1; i++)
    {
        if (text[i] > text[i + 1])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[256];
int letterCount[26] = {0}; // Array to store the count of each letter initialized to zeros

void letter_counter(char *input, int *letterCount)
{
    for (int i = 0; i < strlen(input); i++)
    {
        char letter = input[i];

        if (isalpha(letter))
        {
            letter = toupper(letter);
            int index = letter - 'A';
            letterCount[index]++;
        }
    }
}

int main()
{

    printf("Enter text strings (press Enter on an empty line to exit):\n");

    while (1)
    {
        fgets(input, sizeof(input), stdin); // get the input from the user via keyboard

        // Check for an empty line to exit the loop
        if (strlen(input) == 1 && input[0] == '\n')
        {
            break;
        }
        letter_counter(input, letterCount);

        for (int i = 0; i < 26; i++)
        {
            printf("%c: %d  ", 'A' + i, letterCount[i]);
        }
    }

    return 0;
}

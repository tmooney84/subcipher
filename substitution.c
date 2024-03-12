#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int letter_count = 0; // ? 26 letters
    char key[27];         // encryption key brought in from cli
    char plaintext[100];  // string for plaintext message with 100 character limit
    char ciphertext[100]; // string for ciphertext message with 100 character limit

    // error for more than one entry in cli
    if (argc != 2)
    {
        printf("Usage %s <encryption_key>\n", argv[0]);
        return 1;
    }

    // checking whether if letters only
    for (int i = 0; argv[1][i] != '\0'; i++)
    {

        if (!isalpha(argv[1][i]))
        {
            printf("Error... encryption key includes letters only.\n");
            return 1;
        }
        key[i] = argv[1][i];
        letter_count++;
    }
    key[letter_count] = '\0'; // adds null to terminate string

    // Error if not 26
    if (letter_count != 26)
    {
        printf("ERROR... Encription key is not valid (letters!=26)\n");
        return 1;
    }

    // Checking to see if there are duplications of letters
    for (int i = 0; i < letter_count; i++)
    {
        for (int j = i + 1; j < letter_count; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("ERROR... multiple entries of the same letter\n");
                return 1;
            }
        }
    }

    // input plaintext to be encrypted
    printf("plaintext: \n");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: \n");
    // algorithm for conversion and output
    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))
        {
            ciphertext[j] = key[plaintext[j] - 'A'];
            printf("%c", toupper(ciphertext[j]));
        }

        else if (islower(plaintext[j]))
        {
            ciphertext[j] = key[plaintext[j] - 'a'];
            printf("%c", tolower(ciphertext[j]));
        }

        else if (!isalpha(plaintext[j]))
        {
            ciphertext[j] = plaintext[j];
            printf("%c", ciphertext[j]);
        }
    }
    return 0;
}

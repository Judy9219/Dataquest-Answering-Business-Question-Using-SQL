#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
// make sure there is one command-line argument
    if (argc == 2)
    {
        string checktext = argv[1];
        for (int i = 0, n = strlen(checktext); i < n ; i++)
        {
            if (isdigit(checktext[i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        // prompt user for plaintext
        string plain = get_string("plaintext: ");
        printf("ciphertext: ");
        int key = atoi(argv[1]);
        char cipher;
        for (int i = 0, n = strlen(plain); i < n; i++)
        {
            cipher = rotate(plain[i], key);
            printf("%c", cipher);
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

char rotate(char c, int n)
{
// check if the char in plaintext is alphabat
    if (isalpha(c))
    {
        // if alphabat, check upper or low case
        if (isupper(c))
        {
            // if upper case, use upper case rotate formula
            int alphaindex = (int) c - 65;
            // rotated int to char
            c = (alphaindex + n) % 26 + 65;
        }
        else
        {
            // if lower case, use lower case rotate formula
            int alphaindex = (int) c - 97;
            // rotated int to char
            c = (alphaindex + n) % 26 + 97;
        }
    }
    return c;
}

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool isNumerical(string str);
string Caesar(string plaintxt, int key);


int main(int argc, string argv[])
{
    int key = 0;
    if (argc == 2 && isNumerical(argv[1]))
    {
        key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        string ciphertext = Caesar(plaintext, key);
        printf("ciphertext: %s\n", ciphertext);
    }
    else
    {
        printf("Usage: ./caesar key \n");
        return 1 ;
    }
}

string Caesar(string plaintext, int key)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isalpha(c) && isupper(c))
        {
            plaintext[i] = (((c - 65) + key) % 26) + 65;
        }
        else if (isalpha(c) && islower(c))
        {
            plaintext[i] = (((c - 97) + key) % 26) + 97;
        }
        else
        {
            continue;
        }
    }
    return plaintext;
}


bool isNumerical(string str)
{
    for (int i = 0, n = strlen(str) ; i < n ; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool isAlphabetical(string str);
string convertKey(string key);
string Cipher(string plaintext, string key);
bool isDuplicated(string key);

int main(int argc, string argv[])
{
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        if (isAlphabetical(argv[1]) && !isDuplicated(argv[1]))
        {
            string key = convertKey(argv[1]); //make the key containing of upper cases
            string plaintext = get_string("plaintext: ");
            string ciphertext = Cipher(plaintext, key);
            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }
        else if (!isAlphabetical(argv[1]) || isDuplicated(argv[1]))
        {
            printf("Key must contain alphabetical and not dublicated characters.\n");
            return 1;
        }
    }
    else if (argc == 2 && strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

bool isAlphabetical(string str)
{
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (!isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}

string convertKey(string key)
{
    for (int i = 0; i < 26; i++)
    {
        if (islower(key[i]))
        {
            key[i] -= 32;
        }
    }
    return key;
}

string Cipher(string plaintext, string key)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        if (isalpha(c) && isupper(c))
        {
            plaintext[i] = key[(c - 65)];
        }
        else if (isalpha(c) && islower(c))
        {
            plaintext[i] = key[(c  - 97)] + 32;
        }
        else
        {
            continue;
        }
    }
    return plaintext;
}

bool isDuplicated(string key)
{
    key = convertKey(key); //it can contain same letter in both cases
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (key[i] == key[j])
            {
                return true;
            }
        }
    }
    return false;
}

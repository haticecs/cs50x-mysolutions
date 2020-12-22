#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

bool isAlphabetical(char c);
int numOfLetters(string str);
int numOfWords(string str);
int numOfSentences(string str);
float calculateIndex(int W, int L, int S);



int main(void)
{
    string input = get_string("Text: ");

    int L = numOfLetters(input);
    int W = numOfWords(input);
    int S = numOfSentences(input);
    int grade = (int)calculateIndex(W, L, S);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

float calculateIndex(int W, int L, int S)
{
    float avgL = 100 * (L / (float)W);
    float avgS =  100 * (S / (float)W);
    return round((0.0588 * avgL) - (0.296 * avgS) - 15.8);

}

bool isAlphabetical(char c)
{
    if ((c >= 'a' && c <= 'z') || (c + 32 >= 'a' &&  c + 32 <= 'z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int numOfLetters(string str)
{
    int res = 0;
    for (int i = 0, n = strlen(str); i < n ; i++)
    {
        if (isAlphabetical(str[i]))
        {
            res ++;
        }
    }
    return res;
}

int numOfWords(string str)
{
    int res = 0;
    for (int i = 0, n = strlen(str); i < n ; i++)
    {
        if (str[i] == 32) // 32 stands for space in ASCII
        {
            res++;
        }
    }
    return res + 1;
}

int numOfSentences(string str)
{
    int res = 0;
    for (int i = 0, n = strlen(str); i < n ; i++)
    {
        if (str[i] == 46 || str[i] == 33 || str[i] == 63)
        {
            res++;
        }
    }
    return res;
}

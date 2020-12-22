#include <stdio.h>
#include <cs50.h>
int calculateDigit(long input);
bool isOdd(int n);
bool checkSum(long input);
void printType(long input);



int main(void)
{
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 0);

    //check the invalid digits like phone numbers
    int digit = calculateDigit(n);
    printf(" %i \n", digit);
         
    if (digit < 13 || digit > 16)
    {
        printf("INVALID\n");
    }
    else
    {
        if (!checkSum(n)) //checkSum
        {
            printf("INVALID\n");
        }
        else //Find the type of the card
        {
            printType(n);
        }
    }

}

int calculateDigit(long input)
{
    int digit = 1;
    while (input / 10 > 0)
    {
        input /= 10;
        digit ++;
    }
    return digit;

}
bool isOdd(int n)
{
    if (n % 2 == 0)
    {
        return false;
    }
    return true;
}

bool checkSum(long input)
{
    int sum0 = 0;
    int sum1 = 0;
    int res = 0;
    int n = 0;

    while (input / 10 >= 0)
    {
        int remainder = input % 10;
        if (isOdd(n)) // n-> 1,3,5 (sum0)
        {
            int temp = remainder * 2;
            if (temp < 10)
            {
                sum0 += temp;
            }
            else //2 digits, most 9*2 = 18
            {
                int digits = temp % 10 + temp / 10;
                sum0 += digits;
            }
        }
        else // n-> 2,4,5
        {
            sum1 += remainder;
        }

        input /= 10;
        n++;
        
        if (input == 0)
        { 
            break;
        }
    }
    

    res = sum0 + sum1;

    if (res % 10 == 0) //to find last digit
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void printType(long input)
{
    int digit = calculateDigit(input);
    int first, second ;
    
    while (input > 99)
    {
        input /= 10;
    }
   
    first = input / 10;
    second = input % 10;

    if (digit >= 13  && digit <= 16 && first == 4)
    {
        printf("VISA\n");
    }
    else if (digit == 15 && (input == 34 || input == 37))
    {
        printf("AMEX\n");
    }
    else if (digit == 16 && (input == 51 || input == 52 || input == 53 || input == 54 || input == 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

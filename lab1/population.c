#include <stdio.h>
#include <cs50.h>

int calculate_years(int start, int end);

int main()
{
    int start_size, end_size;
    do
    {
        start_size = get_int("Start size: ");
    } 
    while (start_size < 9);

    do
    {
        end_size = get_int("End size: ");
    } 
    while (end_size < start_size);

    int years = calculate_years(start_size, end_size);
    printf("Years: %i\n", years);

    return 0;
}

int calculate_years(int start, int end)
{
    int years = 0;
    int result = start;
    
    while (result < end)
    {
        result += ((result / 3) - (result / 4));
        years ++;
    }

    return years;
}
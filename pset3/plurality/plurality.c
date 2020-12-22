#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
int compare_function(const void *elem1, const void *elem2);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election

void print_winner(void)
{
    /* sort function for struct */
    qsort(candidates, candidate_count, sizeof(candidate), compare_function);

    candidate winner = candidates[candidate_count - 1];

    int max_votes = winner.votes;

    printf("%s\n", winner.name);

    /* if there are two winners */
    for (int i = candidate_count - 2; i >= 0 ; i--)
    {
        int curr_votes = candidates[i].votes;

        if (max_votes == curr_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

int compare_function(const void *elem1, const void *elem2)
{
    candidate *f = (candidate *)elem1;
    candidate *s = (candidate *)elem2;

    if (f->votes > s->votes)
    {
        return  1;
    }

    if (f->votes < s->votes)
    {
        return -1;
    }

    return 0;
}
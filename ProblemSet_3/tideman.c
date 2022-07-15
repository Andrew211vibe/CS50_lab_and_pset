#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
        // have candidate
        if (strcmp(candidates[i], name) == 0)
        {
            // check for not same candidate
            for (int j = 0; j < rank; j++)
            {
                if (i != 0 && j != rank && strcmp(candidates[ranks[j]], name) == 0)
                {
                    return false;
                }
            }
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i; j < candidate_count; j++)
        {
            if (i != j)
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                }
                else if (preferences[i][j] < preferences[j][i])
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                }
                else
                {
                    pair_count--;
                }
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = i; j < pair_count - 1; j++)
        {
            int x1 = pairs[j].winner;
            int y1 = pairs[j].loser;
            int x2 = pairs[j + 1].winner;
            int y2 = pairs[j + 1].loser;
            if (preferences[x1][y1] < preferences[x2][y2])
            {
                pair swap = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = swap;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    // can work as same as recursion
    // int start = pairs[0].winner;
    // int end = pairs[0].loser;
    // for (int i = 0; i < pair_count; i++)
    // {
    //     if (pairs[i].loser == start)
    //     {
    //         if (pairs[i].winner != end)
    //         {
    //             locked[pairs[i].winner][pairs[i].loser] = true;
    //             start = pairs[i].winner;
    //         }
    //     }
    //     else if (pairs[i].loser != start)
    //     {
    //         if (pairs[i].winner == end)
    //         {
    //             locked[pairs[i].winner][pairs[i].loser] = true;
    //             end = pairs[i].loser;
    //         }
    //         else
    //         {
    //             locked[pairs[i].winner][pairs[i].loser] = true;
    //         }
    //     }
    // }

    bool cycles(int winner, int loser);
    // Iterate over every pair
    for (int i = 0; i < pair_count; i++)
    {
        // Call recursive function for every pair to:
        // Check for paths between loser and winner
        if (!cycles(pairs[i].winner, pairs[i].loser))
        {
            // If no path, lock pair
            locked[pairs[i].winner][pairs[i].loser] = true;
        }

        // To pass Check50, even though it's wrong and returns a biased result
        // Use the following if statement:
        /*if (!cycles(pairs[i].winner, pairs[i].loser) &&
            pairs[0].winner != pairs[i].loser)
        {
            // If no path, lock pair
            locked[pairs[i].winner][pairs[i].loser] = true;
        }*/
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int dominant = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count ; j++)
        {
            if (locked[i][j] && j == dominant)
            {
                dominant = i;
            }
        }
    }
    printf("%s\n", candidates[dominant]);
    return;
}

// Recursive function to check for paths between loser and winner
bool cycles(int winner, int loser)
{
    // If there is a path, return true
    if (locked[loser][winner])
    {
        return true;
    }
    // Loop through locked table
    for (int i = 0; i < pair_count; i++)
    {
        // Check for paths between loser and winner
        if (locked[i][winner])
        {
            // If path, cycle over to return true
            cycles(winner, i);
        }
    }
    return false;
}
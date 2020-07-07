#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates , MAX is a constant and equates to 9
#define MAX 9

// defines a stuct called candidates,which have 2 fields,name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// defines a global array of candidates where the max is 9 candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes  do these two
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; // argc is the total argument count,-1 to remove plurality the additional command line
    if (candidate_count > MAX) // check if input of candidates > 9
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    // search through the array of candidate,
    for (int i = 0; i < candidate_count; i++)
    {   
        // assigning the candidates name to the input from the user. argv[0] is plurality
        // argv[ 0+1] is the first name of user input
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0; // assign starting votes from 0
    }
    //prompt user for number of voters
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    { 
        // assign name to voted name
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
    // look in the data for a candidate called name , iterate and loop through array candidates
    for (int i = 0; i < candidate_count; i++)
    {
        //check if the name in the vote correponds with the candidates
        if (strcmp(name, candidates[i].name) == 0)
        {  
            //if name belongs to one of the candidates, add that vote to the candidate
            candidates[i].votes++;
            return true; // return 1 
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //first create an int variable, Highest_vote as the base control test with assigned value 
    // highest_vote will be used to record the highest number of votes found
    int highest_vote = 0;
    // search through the array of candidate,
    for (int i = 0; i < candidate_count; i++)
    {
        // sort it, check if the first candidate votes is > 0, if so then highest vote becomes candidates[0].votes, 
        // and then it will check if candidates[1].votes is > candidates[0].votes , if so, highest_vote is candidates[1].votes until all candidates are exhausted 
        if (candidates[i].votes > highest_vote)
        {
            // assign highest_vote as the highest number of votes found
            highest_vote = candidates[i].votes;
        }
    }
    // now that we know the highest vote number, we check through candidates[i].votes to see if it corresponds
    //if it corresponds, we print the candidates[i].name
    //new loop to search through the array
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == highest_vote)
        {
            printf("%s\n", candidates[j].name);
        }
    }
    printf("\n");
}


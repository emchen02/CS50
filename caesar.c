#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    int n = strlen(argv[1]);
    // check all elements of command line argv[1] to see if they are digits
    for (int i = 0; i < n; i++)
    {
        if (isdigit(argv[1][i]) == false) // elements are not all digits, do the code below
        {
            printf("Usage: ./caesar key\n");
            return 1; //to signify error for not enough command line arguments
        }
    }
    // convert second command line to an integer and set it as k which is the key
    int k = atoi(argv[1]); 
    // print plaintext and get user string input and assign it as string called plaintext
    string plaintext = get_string("plaintext: ");
    // find the length of the plaintext and assign it to integer m
    int m = strlen(plaintext);
    // create an array of chars called ciphertext with size + 1 of the plaintext string to copy it
    char ciphertext[m + 1];
    // set last variable of ciphertext to void by putting the null '\0'
    ciphertext[m] = '\0';
    // loop through each char in plaintext 
    for (int i = 0; i < m; i ++)
    {   
        //checks if each char in plaintext is alphabet
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i])) //check if each char is upper
            {
                ciphertext[i] = ((plaintext[i] + k - 65) % 26) + 65; 
            }
            else if (islower(plaintext[i])) //check if each char is lower
            {
                ciphertext[i] = ((plaintext[i] + k - 97) % 26) + 97;
            }
        }
        else //if not alpha,copy char in plaintext to ciphertext without changing
        {
            ciphertext[i] = plaintext[i]; 
        }
    }
    printf("ciphertext: %s\n", ciphertext);  // once finish assigning array, print "ciphertext: "
    return 0; // return 0 to exit main function as code is successfully executed
}

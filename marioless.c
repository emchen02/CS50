// Right aligning without .

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n ; // create a variable integer and name it n
    do {
        n = get_int("Height: "); // prompt user for height input in the form of integer. if not integer, it will continue prompting.
    }
    while (n > 8 || n < 1);                    // prompt user question again while n is not between 1 and 8


    int j = 1;                                 //create a counter j, and start it from 1
    int x = n - j;                             // create another counter x and start it from n -j     
   
    do {                                      //do the code below until j is not >= n . 
        for (int y = 0; y < x; y++) {                                  // make a loop to perform code x time
             printf(" ");                                    // print " " x times
        }
        
        for (int i = 0; i < j; i++) {                                  // make a loop to perform code j times , 1st checks that i = 0 is < j.  
             printf("#") ;                // since j = 1, code prints # 
        }                                // then increment i by 1. now i = 0 + 1 = 1 and is not < j ( since j = 1), so code stops and go to the next code
        
        printf("\n");                  // go to the next line 
        
        j++;                          // followed by incrementing the counter j by 1 , j = 1 +1 = 2
        x--;                              
    }
    while (j <= n);                   // code will run when j < = n, once j > n, code stops
}

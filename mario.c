#include <cs50.h>
#include <stdio.h>


int main(void) 
{
    int n;    //create a variable integer n
 
    do          // do the code below until input n is between 1 and 8
    {
        n = get_int("Height: ");   // get an integer input from user with prompt "Height: ""
    }   
    while (n < 1 || n > 8);   // / if the input is < 1 or > 8, ask for the input till condition is false ie input n is between 1 and 8
  
    int j = 1 ;                        //create a counter j, and start it from 1
   
    int x = n - j;                    // create another counter x and start it from n -j   
  
    do                                // do the code below until j > n,
    {
        for (int i = 0 ; i < x  ; i++)                // do the code  x times, 
        {
            printf(" ");                             //  print space x times
        }    
        
        for (int a = 0; a < j ; a++)                  // then do the next code j times,
        {
            printf("#");                           // print # j times
        }
         
        printf("  ");                             // then print "  " 
        
        for (int a = 0; a < j ; a++)               // then do the next code j times
        {
            printf("#");                         // print # j times
        }
        
        printf("\n");                          // print a new line
     
        j++;                                      // increment j by 1 after printing per row
        x--;                                      // decrement x by 1 after printing per row
    }
        
    while (j <= n);                  // code above will repeat and run when j < = n, once j > n, code stops 
   
}
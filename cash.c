#include <math.h>
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int cents;  //To find out how much change to return in cents, we need to convert the user input from dollars to cents, and assign it as an integer cents since it will be a whole number 
    float dollar;

    do
    {
        dollar = get_float("Change owed: ");  // ask for a float as money change could be in decimals instead of a whole integer.
    }
    while (dollar < 0);
    
    
    cents = round(dollar * 100); // To convert dollars to cent, * 100 and round your cents to the nearest penny 
      
    if (cents % 25 == 0)              // if change in cents gives no remainder when % 25, change can all be given in 25 cents
    {
        printf("%i\n", cents / 25); // divide by 25 to get the number of 25c coins
        
    }
    
    else if (cents % 25 != 0)         // else 
    {
        int balance1 = cents % 25;    //get the balance1 after cents % 25,
        
        if (balance1 % 10 == 0)  // if balance1 gives no remainder when % 10, balance1 can all be given in 10 cents.
        {
            // create an int coins1 and equate it to the addition of number of 25 cents and 10 cents
           
            int coins1 = (cents / 25) + (balance1 / 10); 
            
            printf("%i\n", coins1);
        }
        else if (balance1 % 10 != 0) // else 
        {
            int balance2 = balance1 % 10; //get the balance2 after balance1 % 10
                    
            if (balance2 % 5 == 0) // if balance2 gives no remainder when % 5, balance2 can all be given in 5 cents
            {                       
                int coins2 = (cents / 25) + (balance1 / 10) + (balance2 / 5); // add number of 25 cents, 10 cents and 5 cents   
                  
                                                                
                printf("%i\n", coins2);
            }
            else                              // if balance 2 have a remainder when %5,
            {
                int balance3 = balance2 % 5;  // we need to get the balance2 % 5 and assign it as balance 3 
                // since the last coin denomination is 1 cents, to get the number of 1c coins, we just take balance3 / 1        
                int coins3 = (cents / 25) + (balance1 / 10) + (balance2 / 5) + (balance3 / 1); 
                   
                        
                printf("%i\n", coins3);
            }
        }
    }
}

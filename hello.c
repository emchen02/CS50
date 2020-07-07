#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What is your name?\n");  //create a string variable assign it to user input 
    printf("hello, %s\n", name);  //prints out hello , string input
}
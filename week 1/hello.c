#include <stdio.h>
#include <cs50.h>


int main(void)
{
// prompts for name
    string name = get_string("What is your name?");
// says hello and repeats name
    printf("hello, %s\n", name);

}

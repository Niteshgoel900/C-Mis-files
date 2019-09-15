//Homework 2 - Question 1
#include <stdio.h>

int main(void) 
{
 //Declaring variable
 int number1, number2;

 //User input
 printf("Enter two integers:");
 scanf("%d %d", &number1, &number2);

 //Determining if number1 is a multiple of number2
 if (number1 % number2 == 0)
   {
    printf("%d is a multiple of %d", number1,number2);
    return 0;
   }
 
 //Determining if number1 is not a multiple of number2
 if (number1 % number2 != 0)
   {
    printf("%d isn't a multiple of %d", number1,number2);
    return 0;
   }

 return 0;
} // end function main
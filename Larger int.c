//Homework 1 - Question 1
#include <stdio.h>

int main (void) 
{ 
  // Declaring a variable 
  int number1, number2; 

  // Printing a statment
  printf("%s", "Enter two integers: "); 
  scanf("%d %d", &number1, &number2);

  // Determine if the first integer is larger than the second integer
  if(number1 >number2)  
    printf("%d is larger.\n",number1); 

  // Determine if the second integer is larger than the first integer
  if (number2> number1) 
    printf("%d is larger.\n", number2); 

  // Determine if the two integers are equivalent 
  if (number1 == number2)  
    puts("These numbers are equal."); 

  return 0; 
 } // end function main
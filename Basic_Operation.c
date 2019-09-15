//Homework 1 - Question 5

#include <stdio.h>

int main(void) 
{
  // Declaring a variable
  int a,b,c,x;

  //Prompt for user input
  printf("%s", "Enter a,b, and c in order: ");
  scanf("%d %d %d", &a, &b,&c);

  //Integer x displays the summation of a,b and c
  x=(a + b + c);
  printf("Result:\n");
  //Integer x is printed
  printf("a+b+c = %d\n", x);

  //Integer x displays the product of a,b and c
  x=(a * b * c);
  //Integer x is printed
  printf("a*b*c = %d\n", x);

  return 0;
} // end function main
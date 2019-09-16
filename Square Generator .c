//Homework 3 - Question 8
#include <stdio.h>

int main(void) {
int square;
//the counter is set to -1 because we need to add 2 "*" to the end
int n=-1;

//Asking the user for how big the square should be
printf("Enter an integer between 1 and 20:");
scanf("%d", &square);

//Prints the top line 
while (n <= square) {
    printf("* ");
    n++;
  }

  //Creates a gap from line to line
  printf("\n");

  //prints the body of the square
  n = 1;
  while (n <= square) {
    printf("* ");
    int i = 1;
   while (i <= square) {
    printf("  ");
    i++;
    }
    printf("* \n");
    n++;
  }

  //Prints the last line 
  n=-1;
  while (n <= square) {
    printf("* ");
    n++;
  }
 printf("\n");

  return 0;
}
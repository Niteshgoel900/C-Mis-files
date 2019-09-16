//Homework 3 - Question 2
#include <stdio.h>

int main(void) {
  int userinput;

  printf("Enter a number between 2 and 20: ");
  scanf("%d", &userinput);

  //To make sure that the userinput is between the numbers 2 and 20
  if (userinput>20) {
    printf("Please enter a number between 2 and 20 only!!");
    scanf("%d",&userinput);
  }
  if (userinput<2) {
    printf("Please enter a number between 2 and 20 only");
    scanf("%d",&userinput);
  }

  //whole numbers
  printf("The first %d whole numbers: ", userinput);
  int n=0;
  while(n<userinput){
    printf("%d ", n);
  n++;
  }
 
 //even whole numbers
  printf("\nThe first %d even whole numbers: ", userinput);
  n=0;
  while(n<userinput){
    printf("%d ", n*2);
  n++;
  }

  //odd whole numbers
  printf("\nThe first %d odd whole numbers: ", userinput);
  n=1;
  while(n<userinput){
    printf("%d ", n*2-1);
  n++;
  }

  //whole numbers counting by 7
  printf("\nThe first %d whole numbers counting by 7: ", userinput);
  n=0;
  while(n<userinput){
    printf("%d ", n*7);
  n++;
  }

  //perfect squares
  printf("\nThe first %d perfect squares: ", userinput);
  n=0;
  while(n<userinput){
    printf("%d ", n*n);
  n++;
  }

return 0;
}
//Homework 3 - Question 6
#include <stdio.h>

int main(void) {
  int userinput;
    printf("Do you Have to File n Income Tax return? \n");
    printf("---------------------------------------------------");
    printf("\nNote: Please answer the following questions carefully.\n");
    printf("If you made a mistake in answering the questions,\n");
    printf("please restart the program and start answering the questions.\n");
    //telling the user how to answer the questions
    printf("Use 1 to say Yes and 0 to say No \n");
    printf("---------------------------------------------------\n\n");
    printf("Please answer the following questions:\n");
    //User input needed 
    printf("Are you single?");
    scanf("%d", &userinput);

    //boolean if tree
    if (userinput == 1) {
      //user input question
      printf("Are you under 65 years of age?");
      scanf("%d", &userinput);
        if (userinput == 1) {
        //if yes then print this
        printf("Is your gross income less than $8450?");
        scanf("%d", &userinput);
        //if yes then print this
          if (userinput == 1) {
          printf("You do not have to file an income tax return");
      } 
      //if no to line 23 print this
      else {
       printf("You have to file an income tax return");
      }
    } 
      //if no to line 21 print this
      else {
        printf("Is your gross income less than $9700?");
        scanf("%d", &userinput);
      //if yes to the above question print this
      if (userinput == 1) {
        printf("You do not have to file an income tax return");
      } 
      //if no to the above question print this
      else {
        printf("You have to file an income tax return");
      }
    }
  } 
      //If user says no to the first question print this
      else {
        printf("You have to choose form F-ABC");
        }

  return 0;
}
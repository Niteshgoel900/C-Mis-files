//Homework 3 - Question 3
#include <stdio.h>

int main(void) {
  float total, percent;
  //n will start from 10
  int n=10;
  
  //Asking the user for the total cost
  printf("Enter the total restaurant charge: $");
  scanf("%f", &total);

  printf("------Tipping Chart-----\n");
  printf("Percent\tTip\tTotal");

  //will calculate upto where n is 25 or less
  while(n<=25){
    percent= (float)n/100;
    //Calulating the Tip and adding that to total the tip will be printed seperatly than the total.
    printf("\n%d%%\t$%.2f\t$%.2f", n,total*percent, (total*percent)+total);
    n++;
  }
  printf("\n");
  return 0;
}
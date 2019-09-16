//Homework 3 - Question 4
#include <stdio.h>

int main(void) {
  float principal, rate, interest;
  int days;

  while(""){
    //Ask the user the loan amount
    printf("Enter loan principal (-1 to end):");
    scanf("%f", &principal);

    //if the loan is -1 then the user wont be asked any more questions
    if(principal==-1){
     return 0;
   } 
    //Ask the user the annual interest rate
    printf("Enter annual interest rate:");
    scanf("%f", &rate);
   
    //Ask the user the term of the loan
    printf("Enter term of the loan in days:");
    scanf("%d", &days);

    //Calculating the interest 
    interest = principal * rate * days / 365;

    //Displaying the interest charge 
    printf("The interest charge is $%.2f\n", interest);
  }
  return 0;
}
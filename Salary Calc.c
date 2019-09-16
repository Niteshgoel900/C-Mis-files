#include <stdio.h>

int main(void) {
  //Initalizing variables
  int hours_worked, over, input; 
  float hourly_rate, gross_income;

  do{ 
    printf("The number of hours worked in the week:");
    scanf("%d", &hours_worked);
    printf("Hourly rate:");
    scanf("%f", &hourly_rate); 
    //If the hours worked are less than 40
    if(hours_worked<=40)
    {
    gross_income=hours_worked*hourly_rate;
    printf("The gross weekly pay is: %.2f", gross_income);
    }
    
    else
    {
    //If the hours worked are more than 40
    over= hours_worked-40;
    gross_income=40*hourly_rate+(1.5*over*hourly_rate);
    printf("The gross weekly pay is: %.2f", gross_income);
    }
    //Informing the user how to end teh loop
    printf("\nWould you like to continue choose 1 to continue and 0 to stop?");
    scanf("%d", &input);
  } while (input==1);
  
return 0;
}
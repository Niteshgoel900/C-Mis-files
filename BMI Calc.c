//Homework 2 - Question 5
#include <stdio.h>

int main(void) 
{
  //Declaring variable
  int WeightInpounds, HeighttIninches, BMI;

  //Printing the header
  printf("----------------------------------------------------------\n");
  printf("           Body mass calculator (BMI)\n");
  printf("The formula and the standard used in this application are from the Department of Health and Human Services/National Institutes of Health so the user can evaluate his/her BMI:\n");
  printf("----------------------------------------------------------\n");

  //User input
  printf("\nPlease enter your weight in pounds:");
  scanf("%d", &WeightInpounds);

  //User input
  printf("Please enter your height in inches:");
  scanf("%d", &HeighttIninches);

  //Using the values inputed by the user to calulate BMI using the formula
  BMI= ((WeightInpounds*703)/(HeighttIninches*HeighttIninches));
  printf("Your BMI = %d\n", BMI);
  printf("\n----------------------------------------------------------\n");

  //Printing (*) if the BMI is under to 18.5
  if(BMI<18.5){
    printf("BMI VALUES\n");
    printf("Underweight: less than 18.5       (*)\n");
    printf("Normal:      between 18.5 and 24.9\n");
    printf("Overweight:  between 25 and 29.9\n");
    printf("Obese:       30 or greater\n");
    printf("-----------------------------------------------------------\n");
      return 0;
  } 

  //Printing (*) if the BMI is greater than or equal to 18.5 but below 24.9
  if(BMI>=18.5){
   if(BMI<24.9){
    printf("BMI VALUES\n");
    printf("Underweight: less than 18.5\n");
    printf("Normal:      between 18.5 and 24.9       (*)\n");
    printf("Overweight:  between 25 and 29.9\n");
    printf("Obese:       30 or greater\n");
    printf("-----------------------------------------------------------\n");
      return 0;
    }
  }

//Printing (*) if the BMI is greather than or equal to 25 but below 29.9 
 if(BMI>=25){
  if(BMI<=29.9){
    printf("BMI VALUES\n");
    printf("Underweight: less than 18.5\n");
    printf("Normal:      between 18.5 and 24.9\n");
    printf("Overweight:  between 25 and 29.9       (*)\n");
    printf("Obese:       30 or greater\n");
    printf("-----------------------------------------------------------\n");
      return 0;
    }
  }

 //Printing (*) if the BMI is greater than or equal to 30
 if(BMI>=30){
    printf("BMI VALUES\n");
    printf("Underweight: less than 18.5\n");
    printf("Normal:      between 18.5 and 24.9\n");
    printf("Overweight:  between 25 and 29.9\n");
    printf("Obese:       30 or greater       (*)\n");
    printf("-----------------------------------------------------------\n");
      return 0;
  }

  return 0;
} // end function main
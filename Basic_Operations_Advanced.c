//Homework 2 - Question 1
#include <stdio.h>

int main(void)
{
  //Declaring variable 
  int number1, number2, number3, tempvalue; 

  //User input
  printf("%s", "Enter three diffrent integers: "); 
  scanf("%d %d %d", &number1, &number2, &number3);

  //calculating the sum of three integers
  tempvalue=(number1 + number2 + number3);
  printf("Sum is %d\n", tempvalue);

  //calculating the average of three integers
  tempvalue= (number1 + number2 + number3)/3;
  printf("Average is %d\n", tempvalue);

  //calculating the product of three integers 
  tempvalue= (number1 * number2 * number3);
  printf("Product is %d\n", tempvalue);

  //Checking if number1 is smaller than the other two integers 
  if(number1<number2) 
    if(number1<number3)
      printf("Smallest is %d\n", number1);

  //Checking if number2 is smaller than the other two integers 
  if(number2<number1) 
    if(number2<number3)
      printf("Smallest is %d\n", number2);
  
  //Checking if number3 is smaller than the other two integers 
  if(number3<number1) 
    if(number3<number2)
      printf("Smallest is %d\n", number3);

  //Checking if number1 is larger than the other two integers 
  if(number1>number2)
    if(number1>number3)
      printf("Largest is %d\n", number1);

  //Checking if number2 is larger than the other two integers 
  if (number2>number1) 
    if(number2>number3)
      printf("Largest is %d\n", number2);

  //Checking if number3 is larger than the other two integers 
  if (number3>number1) 
    if(number3>number2)
      printf("Largest is %d\n", number3);

  return 0;
} // end function main
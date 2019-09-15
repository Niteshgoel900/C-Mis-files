//Homework 1 - Question 2
# include <stdio.h>

int main (void)
{ 
  int radius;

  // Prompt user and obtain inputs
  printf("%s",  "Enter the radius of a circle as an integer: "); 
  scanf("%d" , &radius);

  // Calculate and and print solution
  printf("For a circle with radius %d:\n", radius); 
  printf("Diameter = %d\n" , radius + radius ); 
  printf("Circumference = %f\n", 2 * 3.14159 * radius ); 
  printf("Area = %f\n", 3.14159 * radius * radius );
  return 0;  
} // end function main
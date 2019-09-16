#include <stdio.h>

int main(void) 
{
int side1, side2, side3;

printf("Enter three side of a triangle:");
scanf("%d %d %d", &side1, &side2, &side3);

if(side1*side1 + side2*side2==side3*side3){
  printf("This is a right triangle");
  return 0;
}

if(side1*side1 + side2*side2!=side3*side3){
  printf("This is not a right triangle");
  return 0;
}

  return 0;
}
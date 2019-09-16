#include <stdio.h>

int main(void) {
  int width, length, perimeter, area, remainder, quotient; 
  
  printf("Enter the width of the rectangle:");
  scanf("%d", &width);

  printf("Enter the length of the rectangle:");
  scanf("%d", &length);

  perimeter=(width + length)*2;
  printf("The perimeter of the rectangle is: %d\n", perimeter);

  area=(width*length);
  printf("The area of the rectangle is: %d\n", area);

  quotient= (length/width);
  printf("The quotient of the rectangle is: %d\n", quotient);

  remainder= (length % width);
  printf("The remainder of the rectangle is: %d\n", remainder);


  return 0;
}
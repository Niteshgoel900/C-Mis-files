#include <stdio.h>

int main(void) {
  int x;
  printf("Enter an integer:");
  scanf("%d", &x);
  
  if(x%2==0)
  {
    printf("The integer entered is an even number");
    return 0;
  }
  printf("The integer entered is an odd number");



  return 0;
}
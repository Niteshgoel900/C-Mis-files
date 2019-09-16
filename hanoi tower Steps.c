#include <stdio.h>

void hanoi(int number_of_disks, int peg1, int peg2, int tempPeg){
  if (number_of_disks == 1) {
    printf("\n%d -> %d", peg1, peg2);
  } 
  else {
    hanoi(number_of_disks-1, peg1, tempPeg, peg2);
    printf("\n%d -> %d", peg1, tempPeg);
    hanoi(number_of_disks-1, tempPeg, peg2, peg1);
  }
}
int main(void) {
  int number_of_disks;
  printf("How many rings are there?");
  scanf("%d",&number_of_disks);
  hanoi(number_of_disks,1,2,3);
  printf("\n");
  return 0;
}
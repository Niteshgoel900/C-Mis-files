#include <stdio.h>

// This function is to find the product of input
// Number entered 232=12
int productDigits(int number)
{
  if(number<10)
    return number;
  return (number%10)*productDigits(number/10);
}


// This function is to convert decimal to binary 
int toBinary(int decimalNo) 
{
  if(decimalNo == 0)
    return 0;
  if(decimalNo == 1)
    return 1;

  return (10*toBinary(decimalNo/2))+decimalNo%2;
}

// This function will calculate the product of an array
// [7,5,8] this will do: 
// (1*7)+(2*5)+(3*8)=41
int weightedSum(int numbers[], int n) {
 if (n == 0) return 0;
 return n*numbers[n-1] + weightedSum(numbers, n-1);
}

//This function checks if the array is sorted
int isSorted(int *array, int max, int n)
{
  if(n == 0) 
    return 1;

  if (array[n-1] > max) 
    return 0;
    
  return isSorted(array,array[n-1],n-1);
}

// This is to find Greatest common deminator
int GCD(int a,int b)
{
     while(a!=b)
     {
          if(a>b)
              return GCD(a-b,b);
          else
             return GCD(a,b-a);
     }
     return a;
}

int GCD_(int a,int b)
{
  if(b==0) return a;
  else return GCD_(b,a%b);
}

/*
22 50
1)GCD(50,22%50) == GCD(50, 22)
2)GCD(22,50%22) == GCD(22,6)
3)GCD(6,22%6) == GCD(6,4)
4)GCD(4,6%4) == GCD(4,2)
5)GCD(2,4%2) == GCD(2,2)
6)GCD(2,2%2) == GCD(2,0)

int main(void) {
  int p,x,y,z, i;
  p = GCD(22, 50);  // 2
  x = GCD(10, 160); // 10
  y = GCD(23, 50);  // 1
  z = GCD(60, 15);  // 15
  i = GCD(55, 55);  // 55
    printf("%d\n", p);
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", z);
    printf("%d\n", i);
  return 0;
}*/
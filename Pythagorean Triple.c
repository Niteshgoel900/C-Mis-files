#include <stdio.h>

int main(void) {
  //Initalizing variables
  int a,b,c;
  int x=1;
  //Creating a triple for loop
  for(a=1; a<=500; a++)
  {
    for(b=1; b<=500; b++)
    {
      for(c=1; c<=500; c++)
      {
        //Checking to make sure its a Pythagorean Triple
        if(a*a+b*b==c*c)
        {
          printf("Set %d - Pythagorean Triple: {%d,%d,%d}\n",x,a,b,c);
            x++;
        }
        //Checking to make sure its a Pythagorean Triple
        else if(b*b+c*c==a*a)
        {
          printf("Set %d - Pythagorean Triple: {%d,%d,%d}\n",x,a,b,c);
          x++;
        }
        //Checking to make sure its a Pythagorean Triple
        else if(c*c+a*a==b*b)
        {
          printf("Set %d - Pythagorean Triple: {%d,%d,%d}\n",x,a,b,c);
          x++;
        }
      }
    }
  }
  return 0;
}
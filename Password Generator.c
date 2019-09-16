#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<time.h> 


int main(void){
  int Symbols=0,length,Chracter=1,Mixture=1;
  int All_symbols=0,All_Characters=0,All_mixed=0;
  char symbol,mixed,temp,character;  
    printf("How long should the password be?");    
    scanf("%d",&length);
    printf("Should the password contains numbers and characters y or n?");
    scanf("%c %c",&temp,&character);                             
    printf("should the password contain punctuation symbols y or n?");
    scanf("%c %c",&temp,&symbol);                          
    printf("should the password contain mixed case letters y or n?");
    scanf("%c %c",&temp,&mixed);                           
    
    if(symbol=='y'){
      Symbols=1;
      //3 user options
      All_symbols=length/3;
      }     
    if(character=='y'){
      Chracter=1;
      }
    All_Characters=(length-All_symbols)/2;     
    if(mixed=='y'){
      Mixture=1;
    }
    
    All_mixed=length-(All_Characters+All_symbols); 
    int check=Chracter+Symbols+Mixture;          
    if(length<check){       
      printf("The password would not be possible to create due to the length choosen!");
        }      
        else{
        int x=-1;
        srand(time(0));
        char password[length+1];             
        if (Chracter==2){   
          for(int i=1;i<=All_Characters/2;i++)
            password[++x]=48+rand()%10;           
          for(int i=1;i<=(All_Characters-All_Characters/2);i++)
            password[++x]=33+rand()%93;               
              }
              else                             
                for(int i=1;i<=All_Characters;i++){   
                  password[++x]=48+rand()%10;
                }  
                for(int i=1;i<=All_symbols;i++){     
                  password[++x]=58+rand()%2;
                }             
                if (Mixture==2){   
                  for(int i=1;i<=All_mixed/2;i++)      
                    password[++x]=65+rand()%26;               
                  for(int i=1;i<=(All_mixed-All_mixed/2);i++) 
                    password[++x]=97+rand()%26;
                  }
                  else     
                    for(int i=1;i<=All_mixed;i++) 
                    password[++x]=97+rand()%26;
                    password[++x]='\0';                  
                    printf("The new password is: %s\n",password); 
                    }             
return 0;       
}
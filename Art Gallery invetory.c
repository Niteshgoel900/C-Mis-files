#include <stdio.h>
#include<stdio.h>
#include<string.h>

int database_s=0;

char *pStyle[]={"","Abstract","Fine art","Figurative","Modern","Abstract Expressionism","Expressionism"};
char *subject[]={"","Abstract","Landscape","People", "Portrait","Nature","Animal"};
char *size[]={"","Small","Medium","Large","Oversize"};
char *medium[]={"","Acrylic","Oil","Watercolor","Ink","Paint","Spray Paint"};
char *material[]={"","Canvas","Paper", "Wood","Other","Cardboard","Soft"};
char *orientation[]={"","Portait","Landscape","Square"};

typedef struct {
  char   code[10];
  char   artistName[20];
  int    pStyle;
  char   painting_name[100];
  int    subject;
  int    size;
  int    medium;
  int    material;
  int    orientation;
  double price;
}painting;

painting database[1000]={
                          {"NT0001","Nestor Toro",1,"Late Spring", 1,1,1,1,1, 1000.0},
                          {"FM0001","Fabiene Monestier",2, "Sweet Roses",1,1,1,1,1,2300.00},
                          {"NL0001","Nikos Lamprinos",1,"Untitled",1,1,1,1,1,1000.0}
};

void help_menu(){
  printf("-----------------------------------------------------------------------------\n");
  printf("help:\n");
  printf("code:\t\tTwo initials of the artist followed by 4 digits. Example: ab0001\n");
  printf("Style:\t\t1-Abstract 2-Fine Art 3-Figurative 4-Modern 5-Abstract Expresionism 6-Expressionism\n");
  printf("Subject:\t1-Abstract 2-Landscape 3-People 4-Portrait 5-Nature 6-Animal\n");
  printf("Size:\t\t1-Small 2-Medium 3-Large 4-Oversize\n");
  printf("Medium:\t\t1-Acrylic 2-Oil 3-Watercolor 4-Ink 5-Paint 6-Spray Paint\n");
  printf("Material:\t1-Canvas 2-Paper 3-Wood 4-Other 5-Cardboard 6-Soft\n");
  printf("Orientation:\t1-Portrait 2-Landscape 3-Square\n");
  printf("Price:\n");
  printf("-----------------------------------------------------------------------------\n");
}


void p_rows(int row){
  printf("%d", row+1);
  printf("\t%s", database[row].code);
  printf("\t%s", database[row].artistName);
  printf("\t%s", pStyle[database[row].pStyle]);
  printf("\t%s", database[row].painting_name);
  printf("\t%s", subject[database[row].subject]);
  printf("\t%s", size[database[row].size]);
  printf("\t%s", medium[database[row].medium]);
  printf("\t%s", material[database[row].material]);
  printf("\t%s", orientation[database[row].orientation]);
  printf("\t%lf", database[row].price);
}

void printAll(void){
  printf("\nList of the available paintings in the gallery:\n");
  printf("--------------------------------------------------------------------------------------------------------------------\n");  
  printf("Item");
  printf("\tCode");
  printf("\tArtist Name");
  printf("\tStyle");
  printf("\tPainting Name");
  printf("\tSubject");
  printf("\tSize");
  printf("\tMedium");
  printf("\tMaterial");
  printf("\tOrientation");
  printf("\tPrice");
  printf("\n");
  printf("--------------------------------------------------------------------------------------------------------------------\n");
  for(int i=0; i<=database_s;i++){
    p_rows(i);
    printf("\n");
  }
}

void filterPaintings(void){
  int choice;
  
  printf("-----------------------------------------------------------------------------\n");
  printf("Are you looking for special items? Please see the following help and then add your filters:\n");
  printf("-----------------------------------------------------------------------------\n");
  
  help_menu();
  painting specialPainting={"","",0,"",0,0,0,0,0,0};
  double max_price=0;
  
  printf("Style:"); 
  scanf("%d", &specialPainting.pStyle);
  printf("Subject:"); 
  scanf("%d", &specialPainting.subject);
  printf("Size:"); 
  scanf("%d", &specialPainting.size);
  printf("Medium:"); 
  scanf("%d", &specialPainting.medium);
  printf("Material:"); 
  scanf("%d", &specialPainting.material);
  printf("Orientation:"); 
  scanf("%d", &specialPainting.orientation);
  printf("Minimum Price:"); 
  scanf("%lf", &specialPainting.price);
  printf("Maximum Price:"); 
  scanf("%lf", &max_price);
  printf("\nThe summary of filters:\n");
 
  printf("-----------------------------------------------------------------------------\n");
  printf("Style");
  printf("\tSubject");
  printf("\tSize");
  printf("\tMedium");
  printf("\tMaterial");
  printf("\tOrientation");
  printf("\tMin Price");
  printf("\tMax Price");
  printf("\n");
  printf("-----------------------------------------------------------------------------\n");
  
  printf("%s",pStyle[specialPainting.pStyle]);
  printf("\t%s",subject[specialPainting.subject]);
  printf("\t%s",size[specialPainting.size]);
  printf("\t%s",medium[specialPainting.medium]);
  printf("\t%s",material[specialPainting.material]);
  printf("\t%s",orientation[specialPainting.orientation]);
  printf("\t%lf",specialPainting.price);
  printf("\t%lf",max_price);
  printf("\n\n");
  printf("You applied the above filters. Do you want to verify them (Press 1 for Yes or 0 for No):");
  scanf("%d",&choice);
  
  if(choice){
    printf("\n\nThe list of paintings that you are looking for:\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");  
      printf("Item");
      printf("\tCode");
      printf("\tArtist Name");
      printf("\tStyle");
      printf("\tPainting Name");
      printf("\tSubject");
      printf("\tSize");
      printf("\tMedium");
      printf("\tMaterial");
      printf("\tOrientation");
      printf("\tPrice");
      printf("\n");
      printf("--------------------------------------------------------------------------------------------------------------------\n");  
  for(int i=0; i<=database_s;i++){
    if(database[i].pStyle==specialPainting.pStyle
      &&database[i].subject==specialPainting.subject
      &&database[i].size==specialPainting.size
      &&database[i].medium==specialPainting.medium
      &&database[i].material==specialPainting.material
      &&database[i].orientation==specialPainting.orientation
      &&database[i].price>=specialPainting.price
      &&database[i].price<=max_price){
      p_rows(i);
      printf("\n");
      }
    }
  }
}

void insert_modify(int x){
  char code[10],artists_name[20],Painting_name[100];
  printf("Code:"); 
  scanf("%s", code);
  strcpy(database[x].code,code);
  printf("Artist name:"); 
  scanf("%s",artists_name); 
  strcpy(database[x].artistName,artists_name);
  printf("Styles:"); 
  scanf("%d",&database[x].pStyle);
  printf("Paintings name:"); 
  scanf("%s",Painting_name); 
  strcpy(database[x].painting_name,Painting_name);
  printf("Subject:"); 
  scanf("%d",&database[x].subject);
  printf("Size:"); 
  scanf("%d",&database[x].size);
  printf("Medium:"); 
  scanf("%d",&database[x].medium);
  printf("Orientation:"); 
  scanf("%d",&database[x].orientation);
  printf("Material:"); 
  scanf("%d",&database[x].material);
  printf("Price:"); 
  scanf("%lf",&database[x].price);
}

void addPainting(void){
  printf("-----------------------------------------------------------------------------\n");
  printf("Add Item: Please enter the required data for the new painting:\n");
  help_menu();
  database_s++;
  insert_modify(database_s);
  printAll();
}

void deleteitem(void){
  int del_item_no;
  printAll();
  printf("Which item should be deleted (item no.)? ");
  scanf("%d", &del_item_no);
  strcpy (database[del_item_no-1].code, "" );
  strcpy (database[del_item_no-1].artistName, "" );
  database[del_item_no-1].pStyle = 0;
  strcpy (database[del_item_no-1].painting_name, "" );
  database[del_item_no-1].subject = 0;
  database[del_item_no-1].size = 0;
  database[del_item_no-1].medium = 0;
  database[del_item_no-1].material = 0;
  database[del_item_no-1].orientation = 0;
  database[del_item_no-1].price = 0.0;
  printAll();
}

void modifyitem(void){
  printAll();
  int item_no;
  printf("\nWhich item should be modified:(item no.)?"); 
  scanf("%d",&item_no);
  printf("-----------------------------------------------------------------------------\n");
  printf("\nAdd Item: Please enter the required data for the new painting:\n");
  help_menu();
  insert_modify(item_no-1);
  printAll();
}

char menu(){
  char option;
  printf("-----------------------------------------------------------------------------\n");
  printf("Welcome to Virtual Art Gallery\n");
  printf("-----------------------------------------------------------------------------\n");
  printf("Menu - Select one of the following options:\n");
  printf("Press 'a': To add a painting\n");
  printf("Press 'e': To erase a painting\n");
  printf("Press 'p': To print data for all paintings\n");
  printf("Press 's': To print data for special paintings\n");
  printf("Press 'm': To modify data for a painting\n");
  printf("Press 'x': To exit the program\n");
  printf("Option: ? ");
  scanf("%c", &option);
  return option;
}

int main(){
  char option;
  database_s=3;
  do{
    option= menu();
    switch(option){
      case'a':
        addPainting();
        break;
      case'e':
        deleteitem();
        break;
      case'p':
        printAll();
        break;
      case's':
        filterPaintings();
        break;
      case'm':
        modifyitem();
        break;
      case'x':
        return 0;
      default:
        printf("Please run the code again with proper characters");
    }
    getchar();
  } while(option!='x');
}

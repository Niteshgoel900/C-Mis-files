#include <stdio.h>

#define ROW 12
#define COL 12

char maze[ROW][COL]= 
 {{'#','#','#','#','#','#','#','#','#','#','#','#'},
  {'#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#'},
  {'X',' ','#',' ','#',' ','#','#','#','#',' ','#'},
  {'#','#','#',' ','#',' ',' ',' ',' ','#',' ','#'},
  {'#',' ',' ',' ',' ','#','#','#',' ','#',' ','O'},
  {'#','#','#','#',' ','#',' ','#',' ','#',' ','#'},
  {'#',' ',' ','#',' ','#',' ','#',' ','#',' ','#'},
  {'#','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
  {'#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},
  {'#','#','#','#','#','#',' ','#','#','#',' ','#'},
  {'#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#'},
  {'#','#','#','#','#','#','#','#','#','#','#','#'}};

void print_maze(char maze[ROW][COL]);
void mazeTraverse(int start_x,int start_y,int end_x,int end_y,char maze[ROW][COL],int,int,int);

void mazeTraverse(int start_x,int start_y,int end_x,int end_y,char maze[ROW][COL],int position_of_x,int position_of_y,int x){
  char stop;
  if (position_of_y==end_y & position_of_x == end_x){
      printf("End of Maze\n");
    }  
  else if(x==1){
    if (maze[position_of_y][position_of_x+1]!='#'){
      position_of_x++;
      x=2;
      maze[position_of_y][position_of_x] = '.';
      print_maze(maze);
      printf("Hit enter to see next move:");
      scanf("%c",&stop);
      mazeTraverse(start_x,start_y,end_x,end_y,maze,position_of_x,position_of_y,x);
    }
    else if(maze[position_of_y-1][position_of_x]!='#'){
      position_of_y--;
      maze[position_of_y][position_of_x] ='.';
      print_maze(maze);
      printf("Hit enter to see next move:");
      scanf("%c",&stop);
      mazeTraverse(start_x,start_y,end_x,end_y,maze,position_of_x,position_of_y,x);
    } 
    else if(maze[position_of_y-1][position_of_x]=='#'){ 
      x=4;
      mazeTraverse(start_x,start_y,end_x,end_y,maze,position_of_x,position_of_y,x);
    }
  }
  else if(x==2){
    if (maze[position_of_y+1][position_of_x]!='#'){
      x=3;
      position_of_y++;
      maze[position_of_y][position_of_x] ='.';
      print_maze(maze);
      printf("Hit enter to see next move:");
      scanf("%c",&stop);
      mazeTraverse(start_x,start_y,end_x,end_y,maze,position_of_x,position_of_y,x);
    }
    else if(maze[position_of_y][position_of_x+1]!='#'){
     position_of_x++;
     maze[position_of_y][position_of_x] ='.';
     print_maze(maze);
     printf("Hit enter to see next move:"); 
     scanf("%c",&stop);
     mazeTraverse(start_x,start_y,end_x,end_y,maze,position_of_x,position_of_y,x);
    }
    else if(maze[position_of_y][position_of_x + 1]=='#'){
      x=1;
      mazeTraverse(start_x,start_y,end_x,end_y,maze,position_of_x,position_of_y,x);
    }
  }
  else if(x==3){
    if (maze[position_of_y][position_of_x-1]!='#'){
      x=4;
      position_of_x--;
      maze[position_of_y][position_of_x] = '.';
      print_maze(maze);
      printf("Hit enter to see next move:");
      scanf("%c",&stop);
      mazeTraverse(start_x,start_y,end_x,end_y,maze,position_of_x,position_of_y,x);
    }
    else if(maze[position_of_y+1][position_of_x]!='#'){
      position_of_y++;
      maze[position_of_y][position_of_x]='.';
      print_maze(maze);
      printf("Hit enter to see next move:");
      scanf("%c",&stop);
      mazeTraverse ( start_x,start_y,end_x,end_y,maze,position_of_x,position_of_y,x);
    }
    else if (maze[position_of_y+1][position_of_x]=='#'){
      x=2;
      mazeTraverse(start_x,start_y,end_x,end_y,maze,position_of_x,position_of_y,x);
    }
  }
   else if(x==4){
    if (maze[position_of_y-1][position_of_x]!='#'){
      x=1;
      position_of_y--;
      maze[position_of_y][position_of_x]='.';
      print_maze(maze);
      printf("Hit enter to see next move:");
      scanf("%c",&stop);
      mazeTraverse(start_x,start_y,end_x,end_y,maze,position_of_x,position_of_y,x);
    }
    else if(maze[position_of_y][position_of_x-1]!='#'){
      position_of_x--;
      maze[position_of_y][position_of_x] = '.';
      print_maze(maze);
      printf("Hit enter to see next move:");
      scanf("%c",&stop);
      mazeTraverse(start_x,start_y,end_x,end_y,maze,position_of_x,position_of_y,x);
    }
    else if(maze[position_of_y][position_of_x-1]=='#'){
      x=3;
      mazeTraverse(start_x,start_y,end_x,end_y,maze,position_of_x,position_of_y,x);
    }
  }
}

void print_maze(char maze [ROW][COL]){
 for (int col=0;col<ROW;col++){
    for (int row=0;row<COL;row++){
      printf("%c",maze[col][row]);
    }
    printf("\n");
  } 
}

int main(void){
  int start_x,start_y,end_x,end_y,position_of_x,position_of_y,direction;
  char stop;
  start_x=0;
  start_y=2;
  end_x=11;
  end_y=4;
  direction=1;
  position_of_y = start_y;
  position_of_x=start_x;
  print_maze(maze);
  printf("Hit enter to see next move:");
  scanf("%c",&stop);
  mazeTraverse(start_x,start_y,end_x,end_y,maze,position_of_x,position_of_y,direction);
  return 0;
}


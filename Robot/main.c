#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000
void openMenu();
void printMaze(char *mazeToPrint[SIZE][SIZE]);
int splitCommand(char *input, char delim, char *seperateArr[]);
char *maze[SIZE][SIZE];
char *commands[4];
int currentX=SIZE/2;
int currentY=SIZE/2;
char *pos;
int maxNorth=0;
int maxSouth=0;
int maxWest=0;
int maxEast=0;
int north=0;
int south=0;
int east=0;
int west=0;
//char *tempMaze[SIZE][SIZE]={'a','b','c','d'};

int main(){
    openMenu();
    printMaze(maze);

    //printf("%c",tempMaze[0][1]);
    return 0;
}


void openMenu(){
    for(int i =0; i<SIZE; i++){
      for(int k=0; k<SIZE; k++){
        maze[i][k]="u";
      }}
char *input=(char *)malloc(sizeof(char)*20);
char *pos;


while(fgets(input,20,stdin)){


    if(strcmp(input,"\n")==0){
        break;
    }

    if ((pos=strchr(input, '\n')) != NULL)
    *pos = '\0';
    if(strcmp(input,"gowest")==0){
        currentY--;
         if(east>0){
        east--;
        }
        else{
        west--;
        if(west<maxWest){
        maxWest=west;
        }
        }
        //printf("%d",currentX);
    }
    else if(strcmp(input,"gonorth")==0){
        currentX--;
        if(south>0){
        south--;
        }
        else{
        north--;
        if(north<maxNorth){
        maxNorth=north;
        }
        }
    }
    else if(strcmp(input,"goeast")==0){
        currentY++;
        if(west<0){
        west++;
        }
        else{
        east++;
        if(east>maxEast){
        maxEast=east;
        }
        }
    }
    else if(strcmp(input,"gosouth")==0){
        currentX++;
        if(north<0){
        north++;
        }
        else{
        south++;
        if(south>maxSouth){
        maxSouth=south;
        }
        }
    }
    else{
    splitCommand(input, ' ', commands);
    //printf("%s:",commands[0]);
    maze[currentX][currentY]=".";
    maze[currentX][currentY-1]=commands[0];//left

    maze[currentX-1][currentY]=commands[1];//up

    maze[currentX][currentY+1]=commands[2];//right

    maze[currentX+1][currentY]=commands[3];//down
    /*if(maze[currentX-1][currentY-1]==NULL){
     maze[currentX-1][currentY-1]="u";//left-up
    }
    if(maze[currentX-1][currentY+1]==NULL){
      maze[currentX-1][currentY+1]="u";//right-up
    }
    if(maze[currentX+1][currentY+1]==NULL){
      maze[currentX+1][currentY+1]="u";//right-down
    }
    if(maze[currentX+1][currentY-1]==NULL){
    maze[currentX+1][currentY-1]="u";//left-down
    }*/



    // input is (w o o w) or (w w o 0) etc....

    }


}

}


void printMaze(char *mazeToPrint[SIZE][SIZE]){
    printf("maxEast is :%d maxWest is :%d \n",maxEast,maxWest);
    for(int i =0; i<SIZE; i++){
      for(int k=0; k<SIZE; k++){
      //printf(" i is : %d k is :%d \n",i,k);
      if(((i>=(SIZE/2)+(maxNorth-1)) && i<=((SIZE/2)+(maxSouth)+1))  && ((k>=(SIZE/2)+(maxWest-1)) && k<=((SIZE/2)+(maxEast+1))) ){
      //printf("north is : %d south is %d: ",north,south);
        if(strcmp(mazeToPrint[i][k],"o")==0){
        printf(" ");
        }
        else{
        printf("%s",mazeToPrint[i][k]);
        }
           if(k==(SIZE/2)+(maxEast+1)){
        printf("\n");
        }

      }



     }

    }


        }





int splitCommand(char *input, char delim, char *seperateArr[]){



int counter=0;
        char *tempArr = malloc(sizeof(char) * strlen(input));

        if (input != NULL)
        {
                char *token;
                strcpy(tempArr, input);
                token = strtok(tempArr, &delim);
                seperateArr[counter] = malloc(sizeof(char) * strlen(token));
                strcpy(seperateArr[counter], token);
                counter++;
                while (token != NULL)
                {
                        token = strtok(NULL, &delim);
                        if (token == NULL)
                        {

                                break;
                        }
                        seperateArr[counter] = malloc(sizeof(char) * strlen(token));
                        strcpy(seperateArr[counter], token);
                        counter++;
                }
                return counter;
        }
}


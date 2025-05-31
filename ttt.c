#include <stdio.h>
#include <stdlib.h>

int board[3][3]; 
char cboard[3][3];
char output;
int whoseturn = 1;
int turnnum = 0;
int debug = 0;
int win = 5;

void getmove(){
  int r;
  int c;
  printf("Player %d:\n", (whoseturn));
  scanf("%d %d", &r, &c);
  if ((r == -1) || (c == -1)){
    exit(1);
  }
  if ((r > 2 || r < -1) || (c>2 || c<-2) || (board[r][c] != 0)){
    printf("Incorrect value, try again.\n");
    return;
  }
  board[r][c]= whoseturn;
  if(board[r][c] == 1){
    cboard[r][c] = 'O';
  } else {
    cboard[r][c] = 'X';
  }

  
  printf("Player %d entered %d %d.\n", (whoseturn), r, c);
  
  switch (whoseturn){
  case 1:
    whoseturn = 2; break;
  case 2:
    whoseturn = 1; break;
  }

  if(debug == 1){
    printf("entering debug\n");
    int i; int j; 
    for (i=0; i<3; i++){
      for(j=0; j<3; j++){      
	      printf("%d ", board[i][j]);
      }
    printf("\n");
    }
    printf("\n");
  }
  if (output == 'y'){
    printf("-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n",cboard[0][0],cboard[0][1],cboard[0][2],  cboard[1][0],cboard[1][1],cboard[1][2],  cboard[2][0],cboard[2][1],cboard[2][2]);
  }
  turnnum++;
  if (turnnum == 10){exit(1);}
  return;
}

///////////////

int checkforwin(){
  int i;
  for (i = 0; i<3; i++){
    if ((board[i][0] == board[i][1])&(board[i][0] != 0)){
      if (board[i][1]==board[i][2]){
       
        return board[i][2];
      }
    }
  }

  for (i = 0; i<3; i++){
    if ((board[0][i] == board[1][i])&(board[0][i] != 0)){
      if (board[1][i]==board[2][i]){
 
        return board[2][i];
      }
    }
  }


  if ((board[0][0] == board[1][1])&(board[0][0] != 0)){
    if (board[1][1]==board[2][2]){

      return board[2][2];
    }
  }
  if ((board[0][2] == board[1][1])&(board[1][1] != 0)) {
    if (board[1][1]==board[2][0]){
 
      return board[2][0];
    }
  }
  


  getmove();
  return 5;
}

void setup(){
  int i; int j;
  for (i = 0; i<3; i++){
    for (j = 0; j<3; j++){
      cboard[i][j] = ' ';
    }
  }
  return;
}

///////////////

int main(){
  setup();
  printf("Output Play (y/n):\n");
  scanf("%c", &output);
  printf("You entered %c.",output);
  printf("\nStarting game with 3 x 3 board.\nEach player should enter\na row and col num (eg: 2 0).\n");
  while (win == 5){
    win = checkforwin();
  }
  printf("Player %d is the winner.\n", win);
  printf("-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n",cboard[0][0],cboard[0][1],cboard[0][2],  cboard[1][0],cboard[1][1],cboard[1][2],  cboard[2][0],cboard[2][1],cboard[2][2]);

}

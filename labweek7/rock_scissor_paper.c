#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char* translate(char c);

int main(){
  char rsp[3] = {'O', 'X', '#'};
  // index: 0 < 1 < 2 < 0
  // index: X < O < # < X
  int comp_choice = -1;
  char user_choice = ' ';

  srand(time(NULL));

  printf("Game start!\n");
  while(1){
    printf("Choose rock(O), scissor(X), paper(#)\n");
    scanf("%c", &user_choice);
    getchar();

    comp_choice = rand() % 3; // 0, 1, or 2
    printf("user: %s, computer: %s\n", translate(user_choice), translate(rsp[comp_choice]));

    if(rsp[(comp_choice + 2) % 3] == user_choice){
      printf("You win\n\n");
      break;
    } else {
      printf("You lose\n\n");
    }    
  } 
  
  return 0;
}

char* translate(char c){
  switch(c){
    case 'O':
      return "rock";
      break;
    case 'X':
      return "scissor";
      break;
    case '#':
      return "paper";
      break;
    default:
      return "wrong input";
  }
}
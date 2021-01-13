#include <stdio.h>

int read_and_calc();

int main(){

  printf("result: %d\n", read_and_calc());

  return 0;
}

int read_and_calc(){
  int result = 0;
  char operation;
  int num_in;
  scanf("%d", &result);

  while(1){
    operation = getchar();
		scanf("%d", &num_in);
    if(operation == '+'){ // add
			result += num_in;
    } else if(operation == '-'){ // sub
			result -= num_in;
    } else { // the end
      break;
    }
  }

  return result;
}
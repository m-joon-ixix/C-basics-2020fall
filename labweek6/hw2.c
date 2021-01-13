#include <stdio.h>
#include <math.h>

int main(){
  int n, max2exp = 0;
  scanf("%d", &n);
  while(1){
    if((n / (int)pow(2, max2exp)) == 1) break;
    max2exp++;
  }

  int digit;
  for(int i = max2exp; i >= 0; i--){
    digit = n / (int)pow(2, i);
    printf("%d", digit);
    if(digit == 1) n -= (int)pow(2, i);
  }
  printf("\n");

  return 0;
}
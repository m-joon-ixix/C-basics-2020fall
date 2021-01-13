#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
  int x1, y1, x2, y2, r1, r2;
  double d;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  getchar(); // remove '\n' from buffer
  scanf("%d %d", &r1, &r2);
  getchar();
  d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
  printf("교점이 ");

  if((d == r1 + r2) || (d == abs(r1 - r2))){
    printf("하나 입니다.");
  } else if((d < r1 + r2) && (d > abs(r1 - r2))){
    printf("두 개 입니다.");
  } else {
    printf("없습니다.");
  }

  printf("\n");
  return 0;
}
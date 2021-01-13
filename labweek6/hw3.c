#include <stdio.h>
#include <math.h>

int main(){
  int n;
  double x, y; // standard point
  scanf("%d %lf %lf", &n, &x, &y);
  getchar(); // remove '\n' from buffer
  double x_ans, y_ans, x_cur, y_cur, d, d_min;
  for(int i = 0; i < n; i++){
    scanf("%lf %lf", &x_cur, &y_cur);
    getchar(); // remove '\n' from buffer
    d = sqrt((x_cur - x)*(x_cur - x) + (y_cur - y)*(y_cur - y));
    if(i == 0){
      d_min = d;
      x_ans = x_cur;
      y_ans = y_cur;
      continue;
    }
    if(d < d_min){
      d_min = d;
      x_ans = x_cur;
      y_ans = y_cur;
    }
  }

  printf("The closest point from (%0.2f, %0.2f) is (%0.2f, %0.2f) and distance between them is %0.2f\n", x, y, x_ans, y_ans, d_min);

  return 0;
}
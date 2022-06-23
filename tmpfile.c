#include <stdio.h>
int rn(int x);
int actu_value(int x, int y);

int main()
{
  printf("%f", actu_value(1, 2));
}

int rn(int x)
{
  int A = 48109;
  int B = 2531011;
  int M = 32768;
  return (A * x + B) % M;
}

int actu_value(int x, int y)
{
  double nor_x;
  double nor_y;
  nor_x = (double)x;
  nor_y = (double)y;
  for (int i = 1; i < 10; i++)
  {
    x = rn(x);
    y = rn(y);
    nor_x = ((double)(x % 1001)) * 0.001;
    nor_y = ((double)(y % 1001)) * 0.001;
  }
}

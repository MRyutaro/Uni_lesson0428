#include <stdio.h>
int rn(int x);

int main()
{
  int x = 1;
  for (int i = 1; i < 10; i++)
  {
    x = rn(x);
    printf("%d\n", x % 11);
  }
  return 0;
}

int rn(int x)
{
  int A = 48109;
  int B = 2531011;
  int M = 32768;
  return (A * x + B) % M;
}
#include <stdio.h>

int get_num();
int rn(int x);
int get_arr(int num);
float get_per_arr(float count);

int array[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float per_array[11] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

int main()
{
  int count, random_num_base = 1, random_num;
  // 入力
  count = get_num();
  for (int i = 1; i <= count; i++)
  {
    random_num_base = rn(random_num_base);
    random_num = random_num_base % 11;
    // printf("%d\n", random_num);
    // 回数の配列を更新
    get_arr(random_num);
  }
  // 割合の配列に入れる
  get_per_arr(count);
  for (int i = 0; i < 11; i++)
  {
    printf("%d\t", i);
    printf("%d\t", array[i]);
    printf("%0.2f％\n", per_array[i]);
  }
}

// 入力する関数
int get_num()
{
  int x;
  while (1)
  {
    printf("1000万以下の数値を入力");
    scanf("%d", &x);
    if (1 <= x && x <= 10000000)
    {
      break;
    }
  }

  // return x;
}

// ランダムな数字を出力する関数
int rn(int x)
{
  int A = 48109;
  int B = 2531011;
  int M = 32768;
  return (A * x + B) % M;
}

// 出た回数の配列に入れる
int get_arr(int num)
{
  for (int i = 0; i <= 10; i++)
  {
    if (num == i)
    {
      // numをarrayに代入
      array[i] += 1;
    }
  }
}

// 回数の割合の配列を作る
float get_per_arr(float count)
{
  for (int i = 0; i < 11; i++)
  {
    per_array[i] = array[i] / count;
  }
}

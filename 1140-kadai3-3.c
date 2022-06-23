#include <stdio.h>

int get_num();
int rn(int x);
int get_arr(int num);
int get_per_arr(float count);
int nor();
int display();

int count;
int array[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int nor_array[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main()
{
  int random_num_base = 1, random_num;
  // 入力
  count = get_num();
  for (int i = 1; i <= count; i++)
  {
    random_num_base = rn(random_num_base);
    random_num = random_num_base % 11;
    // 回数の配列を更新
    get_arr(random_num);
  }
  nor();
  display();
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
      array[i] += 1;
    }
  }
}

// 回数の割合の配列の中で一番多い割合を探し、それを基準に正規化
int nor()
{
  int max_num = 0;
  float max = array[0];
  float convert_num;

  // 最大値を求める。
  for (int i = 0; i < 10; i++)
  {
    if (max < array[i + 1])
    {
      max_num = i + 1;
      max = array[i + 1];
    }
  }

  // 正規化する
  convert_num = 20 / max;
  for (int i = 0; i < 11; i++)
  {
    nor_array[i] = array[i] * convert_num;
  }
}

// 結果を表示する関数
int display()
{
  for (int i = 0; i < 11; i++)
  {
    printf("%6d:  ", i);
    for (int j = 1; j <= nor_array[i]; j++)
    {
      printf("*");
    }
    for (int k = 1; k <= 23 - nor_array[i]; k++)
    {
      printf(" ");
    }
    printf("%6d\n", array[i]);
  }
  printf("============================================\n");
  printf(" TOTAL:");
  for (int l = 1; l <= 25; l++)
  {
    printf(" ");
  }
  printf("%6d", count);
}

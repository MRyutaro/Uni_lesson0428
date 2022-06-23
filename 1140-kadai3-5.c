#include <stdio.h>

int input();
int get_range_y();
int theo_value();
int actu_value(int x, int y);
int get_error();
int display();

float count, on_area_num = 0, error;
float x_min, x_max, y_min, y_max, area;
float theo_area, actu_area;

int main()
{
  input();
  get_range_y();
  theo_value();
  actu_value(1, 2);
  get_error();
  display();
  return 0;
}

// 入力する。
int input()
{
  while (1)
  {
    printf("積分区間の下限値aを入力してください。");
    scanf("%f", &x_min);
    printf("積分区間の上限値bを入力してください。");
    scanf("%f", &x_max);
    if (x_min < x_max)
    {
      break;
    }
    else
    {
      printf("下限値よりも上限値を大きくしてください。\n");
    }
  }

  while (1)
  {
    printf("乱数を発生する回数を入力してください。(1000万回以下)");
    scanf("%f", &count);
    if (1 <= count && count <= 10000000)
    {
      break;
    }
  }
}

// ランダムな数値を出す。
int rn(int x)
{
  int A = 48109;
  int B = 2531011;
  int M = 32768;
  return (A * x + B) % M;
}

// ランダムでyの取りうる範囲を考える。
int get_range_y()
{
  // yの最大値を求める
  if ((x_min) * (x_min) < (x_max) * (x_max))
  {
    y_max = (x_max) * (x_max);
  }
  else
  {
    y_max = (x_min) * (x_min);
  }

  // yの最小値は常に０
  y_min = 0;
}

// 理論値を求める。
int theo_value()
{
  theo_area = ((x_max) * (x_max) * (x_max) - (x_min) * (x_min) * (x_min)) / 3;
}

// 四角形の面積
int get_area()
{
  area = (x_max - x_min) * (y_max - y_min);
}

// 実測値をもとめる。
int actu_value(int x, int y)
{
  get_area();
  float nor_x;
  float nor_y;
  nor_x = (float)x;
  nor_y = (float)y;
  for (int i = 1; i <= count; i++)
  {
    x = rn(x);
    y = rn(y);
    nor_x = ((float)(x % 1001)) * 0.001;
    nor_y = ((float)(y % 1001)) * 0.001;
    float re_x = x_min + (x_max - x_min) * nor_x;
    float re_y = y_min + (y_max - y_min) * nor_y;
    if (re_y < (re_x) * (re_x))
    {
      on_area_num += 1;
    }
  }
  actu_area = (on_area_num / count) * area;
}

// 誤差を求める
int get_error()
{
  if (theo_area >= actu_area)
  {
    error = theo_area - actu_area;
  }
  else
  {
    error = actu_area - theo_area;
  }
}

// 結果を表示する。
int display()
{
  printf("---- 計算結果 ----\n");
  printf("積分値(理論値) = %f\n", theo_area);
  printf("積分値(シミュレーション値) = %f\n", actu_area);
  printf("積分値の誤差 = %f\n", error);
}

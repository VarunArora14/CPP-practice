#include <iostream>
using namespace std;

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, a[100];
  cin >> n;
  for (size_t i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int sum = a[0], max_sum = 0, ini_pos = 0;
  for (int i = 1; i < 2 * n; ++i)
  {
    sum += a[i % n];
    if (i < n)
    {
      if (max_sum < sum)
        max_sum = sum;
      else if (sum < 0)
      {
        sum = 0;
        // here we enter the new ini_pos value
        ini_pos = (i + 1) % n;
        // especially for i=n-1
      }
    }
    else
    {
      if (max_sum < sum)
        max_sum = sum;
      else if (sum < 0)
      {
        sum = 0;
        ini_pos = (i + 1) % n;
      }
    }
  }
  return 0;
}

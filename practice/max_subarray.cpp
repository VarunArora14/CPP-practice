#include <iostream>
#include "vector"
using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  long n, k;
  cin >> n >> k;

  long long a[1000000], b[1000000], c = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < k; i++)
  {
    for (int j = 0; j < n; j++)
    {
      b[c++] = a[j];
    }
  }
  c = 3 * n;
  int sum, max_sum;

  // start from the first element and keep moving p2 forward and store the values when window with max subarray is found
  sum = max_sum = b[0];
  for (size_t i = 1; i < c; i++)
  {
    if (sum + b[i] > sum)
    {
      sum += b[i];
      max_sum = max(sum, max_sum);
    }
    else
    {
      sum = 0;
    }
  }
  cout << max_sum << "\n";

  return 0;
}
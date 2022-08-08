// https://www.geeksforgeeks.org/rotate-matrix-90-degree-without-using-extra-space-set-2/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void sol(vvi &nums)
{
  int n = nums.size();
  int m = nums[0].size();

  // take transpose by swapping nums[i][j] with nums[j][i]
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < m; j++)
    {
      swap(nums[i][j], nums[j][i]);
    }
  }

  // reverse the columns to get the 90 degree rotated ans
  int i1 = 0, i2 = n - 1;
  while (i1 < i2)
  {
    swap(nums[i1], nums[i2]);
    i1++;
    i2--;
  }
}

int main()
{
  vvi nums = {{1, 2, 3, 4},
              {5, 6, 7, 8},
              {9, 10, 11, 12},
              {13, 14, 15, 16}};
  sol(nums);
  for (auto &i : nums)
  {
    for (int &j : i)
    {
      cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}

/*
Input:
 1  2  3
 4  5  6
 7  8  9
Output:
 3  6  9
 2  5  8
 1  4  7

 transpose must give

 1 4 7
 2 5 8
 3 6 9
*/
// https://www.geeksforgeeks.org/a-boolean-matrix-question/
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

void sol1(vvi &nums)
{
  int n = nums.size();
  int m = nums[0].size();

  if (n == 0 || m == 0)
    return;

  vi rows(n, 0), cols(m, 0); // store for a given row or column if there exists nums[i][j]=1

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (nums[i][j] == 1)
      {
        rows[i] = 1;
        cols[j] = 1;
      }
    }
  }

  // now make all ele of that row and col as 1

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (rows[i] == 1 || cols[j] == 1)
      {
        nums[i][j] = 1;
      }
    }
  }
}

// Time is O(nm), space is O(n+m)

// Reduce this space to const

void sol2(vvi &nums)
{
  int col0 = 0;
  int n = nums.size();
  int m = nums[0].size();

  for (int i = 0; i < n; i++)
  {
    if (nums[i][0] == 1)
      col0 = 1;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (nums[i][j] == 1)
      {
        if (j != 0)
        {
          nums[i][0] = 1;
          nums[0][j] = 1;
        }
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (nums[i][0] == 1 || nums[0][j] == 1)
      {
        nums[i][j] = 1;
      }
    }
  }

  if (col0 == 1)
  {
    for (int i = 0; i < n; i++)
      nums[i][0] = 1;
  }
}

int main()
{

  vvi nums = {{1, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  sol1(nums);

  for (auto &i : nums)
  {
    for (auto &j : i)
    {
      cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}

/*
If matrix[i][j]=1 then make all the ele of jth col and ith row as 1

1. We can have 2 arrays of size n and m where n is row length and m is column length.

000
100
000

rows =[0,1,0] cols=[1,0,0]

000
010
000

if matrix[i][j]=1 then make matrix[0][j] and matrix[j][0] as 1
col0 which would store whether the first col has nums[i][0] as 1 or not
*/
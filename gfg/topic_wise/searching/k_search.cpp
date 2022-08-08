// https://www.geeksforgeeks.org/search-insert-position-of-k-in-a-sorted-array/
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

void sol1(vi &nums, int &k)
{
  int n = nums.size();
  if (n == 0)
  {
    cout << -1;
    return;
  }

  int pos = -1;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == k)
    {
      pos = i;
      break;
    }
  }
  cout << "pos is " << pos;
}

void sol2(vi &nums, int &k)
{
  int n = nums.size();
  if (n == 0)
  {
    cout << -1;
    return;
  }

  int lo = 0, hi = n - 1; // upper and lower limit of the values
  int pos = -1;
  // [1]
  while (lo <= hi)
  {
    int mid = lo + (hi - lo) / 2;

    if (nums[mid] == k)
    {
      pos = mid;
      break;
    }
    else if (nums[mid] > k)
    {
      hi = mid - 1;
    }
    else
      lo = mid + 1;
  }

  cout << "pos is " << pos;
}

int main()
{
  vi nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int k = 1;
  sol1(nums, k);
  cout << "\n";
  sol2(nums, k);
  return 0;
}

/*
Here the arra is sorted and you have to find k in the array and return it's position.
There can be 2 ways -
1. linear search
2. binary search
*/
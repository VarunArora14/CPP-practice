// https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/
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

// upper bound idx
int upper(vi &nums, int k)
{
  // [1,2,5,5,5,7]
  int n = nums.size();

  int lo = 0, hi = n - 1;
  int ans = 0;

  while (lo <= hi)
  {
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] <= k)
    {
      lo = mid + 1;
      if (nums[mid] == k)
        ans = mid;
    }
    else
      hi = mid - 1;
  }
  return ans; // idx of upper value
}

int lower(vi &nums, int k)
{
  // [1,2,5,5,5,7]
  int n = nums.size();

  int lo = 0, hi = n - 1;
  int ans = 0;

  while (lo <= hi)
  {
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] >= k)
    {
      hi = mid - 1; // loop goes unlimited as hi=mid makes edge case where lo=hi=mid
      if (nums[mid] == k)
        ans = mid;
    }
    else
      lo = mid + 1;
  }
  return ans; // idx of upper value
}

void sol(vi &nums, int k)
{
  int up = upper(nums, k);
  int low = lower(nums, k);
  cout << "the starting is at " << low << " and ending at " << up;
}

int main()
{
  vi nums = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
  int k = 8;
  sol(nums, k);
  return 0;
}

/*
For sorted array, find the first and last occurence of a number. We can do linear search easily but binary search also an option
*/
// TODO
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

// [5,1,2,3,4] RR and [2,3,4,5,1] LR  [1,2,3,4,5]

// we have to find whether the mid lies in left incline or right incline as the array is sorted
void sol(vi &nums, int k)
{
  int n = nums.size();
  int pos = -1;
  if (n == 0)
    return;

  int lo = 0, hi = n - 1;
  while (lo <= hi)
  {
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] == k)
    {
      pos = mid;
      break;
    }

    // check for rotation
    if (nums[mid] >= nums[lo])
    {
    }
  }
}

int main()
{

  return 0;
}
/*
We have to do BS here as the main way to solve
There can be 3 cases -
1. Not rotated
2. Left rotation and
3. Right Rotation
*/

// 5,6,7,1,2
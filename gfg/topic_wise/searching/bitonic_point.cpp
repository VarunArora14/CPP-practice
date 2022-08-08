// https://www.geeksforgeeks.org/find-bitonic-point-given-bitonic-sequence/
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

// linear O(n)
void sol1(vi &nums)
{
  int n = nums.size();

  if (n <= 2)
  {
    cout << -1;
    return;
  }

  int pos = -1;
  for (int i = 1; i < n - 1; i++)
  {
    if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
    {
      pos = i;
      break;
    }
  }
  cout << "pos is " << pos;
}

void sol2(vi &nums)
{

  int n = nums.size();
  if (n <= 2)
  {
    cout << -1;
    return;
  }

  // [3,1,2]
  int lo = 1, hi = n - 2; // the point will always lie within this range
  int pos = -1;
  while (lo <= hi)
  {
    int mid = lo + (hi - lo) / 2;

    if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
    {
      pos = mid;
      break;
    }
    else if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
    {
      // we are on the left so go lo=mid+1
      lo = mid + 1;
    }
    else
      hi = mid - 1;
  }
  cout << "pos is " << pos;
}

int main()
{
  vi nums = {6, 7, 8, 11, 9, 5, 2, 1};
  sol1(nums);
  return 0;
}

/*
[1]
[2,3,1]
[6, 7, 8, 11, 9, 5, 2, 1]

For BS, lo=0 and hi=n-1. For nums[mid] > nums[lo] and nums[mid] < nums[hi] then go right or mid+1
else if nums[mid] > nums[hi] and nums[mid] < nums[lo] then we are on right(decreasing) so go left
else we are
*/
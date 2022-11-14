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
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define F first
#define S second

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpii = vector<pair<int, int>>;

const int mod = 1000000007;

// https://leetcode.com/problems/first-missing-positive/solutions/858526/cyclic-sort-explained/
int findMissing(vi &nums)
{
  int n = nums.size();
  // till the current number if >0 and <n and does not match it's index, swap it
  for (int i = 0; i < n; i++)
  {
    while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
    {
      int j = nums[i] - 1;    // the position where nums[i] must be at
      swap(nums[i], nums[j]); // keep swapping till either at correct idx or false above condition
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (nums[i] != i + 1)
    {
      return i + 1;
    }
  }

  return n + 1; // if all correct the next number after n is the ans
}
// the reason it works is as we have to find the correct indices from 0 to n for 1 to n+1 and check for 1 wrong value
// as we do swaps we try to assign the correct index to ith value trying to minimize the swaps
// NOTE - this is unstable sorting algo

// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/solutions/2809008/level-order-traversal-cyclesort/?orderBy=most_votes
int cycleSort(vi &nums)
{
  int n = nums.size();
  int len = n;
  map<int, int> mp;

  fo(i, n) mp[nums[i]] = i;

  // NOTE - sort is after mapping
  vi sorted = nums;
  sort(sorted.begin(), sorted.end());

  vector<bool> vis(n, false);
  int ans = 0, count = 0;

  for (int i = 0; i < n; i++)
  {
    // at each nums[i] put the correct value and make changes in map and nums
    if (nums[i] != sorted[i])
    {
      nums[mp[sorted[i]]] = nums[i]; // at index where sorted[i] was, store the value as nums[i] for swap - I
      mp[nums[i]] = mp[sorted[i]];   // earlier sorted[i] was stored at some other index which we change as 'i' later and for nums[i] we set as mp[sorted[i]]
      // above we store this higher index which was earlier associated to sorted[i] to nums[i] as we swapped them
      mp[sorted[i]] = i;   // update correct index in map for smallest value as i
      nums[i] = sorted[i]; // store smallest value in nums[i] - II
      count++;             // swap added
    }
    // I and II is where value swaps are done
  }
  return count;
}

// another variant of above approach
int cycleSort2(vector<int> &arr)
{
  int n = arr.size(), ans = 0;

  vector<pair<int, int>> curr(n);

  // since this array not from 0 to n, we assign initial values and then look for cycle
  for (int i = 0; i < n; i++)
  {
    curr[i].first = arr[i];
    curr[i].second = i;
  }

  sort(curr.begin(), curr.end());

  vector<bool> vis(n, false);

  for (int i = 0; i < n; i++)
  {
    // if seen in cycle before or at correct sorted place
    if (vis[i] || curr[i].second == i)
    {
      continue;
    }

    int cnt = 0, j = i;

    while (!vis[j])
    {
      vis[j] = 1;
      j = curr[j].second; // go to next value to find the cycle
      cnt++;
    }

    if (cnt > 0)
    {
      ans += (cnt - 1); // one extra node as 3 nodes means 2 swaps so add 2
    }
  }

  return ans;
}

int main()
{
  int n;
  cin >> n;
  vi nums(n);
  fo(i, n) cin >> nums[i];

  // for (int i = 0; i < n; i++)
  // {
  //   cin >> nums[i];
  // }

  cout << cycleSort2(nums);
  return 0;
}

// this technqiue works best when we want to do minimum number of swaps

// https://leetcode.com/discuss/study-guide/1902662/cyclic-sort-very-important-and-less-known-pattern
// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/solutions/2809008/level-order-traversal-cyclesort/?orderBy=most_votes
// https://www.geeksforgeeks.org/longest-consecutive-subsequence/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include "unordered_set"

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

// Sort and remove the repetetive and count the consecutive. This is O(n) space and O(nlogn) time for sorting
void sol1(vi nums, int n)
{
  sort(nums.begin(), nums.end());
  vi temp;
  temp.push_back(nums[0]);

  for (int i = 1; i < n; i++)
  {
    if (nums[i] == nums[i - 1])
      continue;
    temp.push_back(nums[i]);
  }

  for (int &i : temp)
    cout << i << " ";
  cout << "\n";
  // Once we have unique sorted ele, we can find the consecutive nums

  int count = 1, maxcount = 1;
  for (int i = 1; i < temp.size(); i++)
  {
    if (temp[i] == temp[i - 1] + 1)
    {
      count++;
      maxcount = max(maxcount, count);
    }
    else
      count = 1;
  }

  cout << "longest consecutive subsequence len is " << maxcount;
}
// Using set can give the same time and space as insertion of ele takes nlogn time in set and max n space.

// Using unordered_set can improve to O(n) time and O(n) space
void sol2(int n, vi nums)
{
  unordered_set<int> us; // will not insert the duplicates

  for (int &i : nums)
    us.insert(i);

  int maxlen = 1, j = 1;
  for (int &num : nums)
  {
    // try to reach the smallest value of a subsequence
    if (us.find(num - 1) != us.end())
      continue;

    // once we reach the smallest value
    j = 1;
    // keep increasing j till us has num+j value as that is the len with j=1 at start
    while (us.count(num + j))
      j++;
    maxlen = max(maxlen, j);
  }
}
// To make this O(n), we go num-- till we reach the smallest value
// Consider example [1,2,3,4,5]. Since nums[0]-1 = 0 not exists, we keep finding if it's next ele exists using nums[i]+j and maxlen = max(maxlen,j);
// for nums[1], nums[1]-1 =1 exists so ignore it as we want to search for the smallest value and then increment for the ans

// [1,2,3,8,18,25,7,6] first we find subsequence len=3 for 1,2,3 starting at 1. Then we ignore 8 as 7 exists in us and for 18, 25 the len is 1, ignore 7 as
// 6 exists and at 6 we find the maxlen as 3 again so ans is 2

int main()
{
  vi nums = {1, 9, 3, 10, 4, 20, 2};
  int n = nums.size();
  sol1(nums, n);
  return 0;
}

// Find the longest subsequence where nums occuring are consecutive in diff order
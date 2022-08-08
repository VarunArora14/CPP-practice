// https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/
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

vi ans;
void subset_sum(vi &nums, int n, int start, int sum)
{
  // base case
  if (start == n)
  {
    ans.push_back(sum);
    return;
  }
  // element not picked
  subset_sum(nums, n, start + 1, sum);

  // element picked
  subset_sum(nums, n, start + 1, sum + nums[start]);
}

int main()
{
  int n;
  cin >> n;
  vi nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  subset_sum(nums, n, 0, 0);
  sort(ans.begin(), ans.end());
  for (int num : ans)
    cout << num << " ";
  return 0;
}

/*
given an array, print sum of all possible subsets in increasing order
subsets of n ele is 2^n

For each ele call function which chooses and does not choose the current ele
3
1 2 3
*/
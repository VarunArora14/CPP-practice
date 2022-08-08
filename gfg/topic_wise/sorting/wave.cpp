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

void sol(vi &nums, int n)
{
  // even indices only
  for (int i = 0; i < n; i = i + 2)
  {
    // check the left and then right
    if (i > 0 && nums[i] < nums[i - 1])
      swap(nums[i], nums[i - 1]);

    // check for right
    if (i < n - 1 && nums[i] < nums[i + 1])
      swap(nums[i], nums[i + 1]);
  }

  for (int &i : nums)
    cout << i << " ";
}

int main()
{
  vi nums = {1, 4, 5, 3, 2, 6, 8, 4};
  int n = nums.size();

  sol(nums, n);
  return 0;
}
/*
Sort in wave form meaning for 1 to 5 make ans as [2,1,4,3,5] where arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= ...

One solution can be nlogn where you sort the ele first and then swap the alternate elements which is nlogn time.
There is another way doing in O(n) time which is for even indices, check the left and right and if nums[i]<nums[i-1] or nums[i]<nums[i+1], swap them
by this, even indices will have greater values than their left and right leading to wave answer.
*/
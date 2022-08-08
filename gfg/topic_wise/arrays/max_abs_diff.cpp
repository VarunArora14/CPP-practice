// https://www.geeksforgeeks.org/maximum-absolute-difference-value-index-sums/
// IMPORTANT
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

void sol(vi nums)
{
  int n = nums.size();

  int mx1 = INT_MIN, mx2 = INT_MIN, mn1 = INT_MAX, mn2 = INT_MAX, ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; i++)
  {
    // for eq1 and 2 find nums[i]+i as max and min as they give the same ans as mod taken. Find largest and smallest and take their diff as abs()
    mx1 = max(mx1, nums[i] + i); // maximize for (a[i]+i) - (a[j]+j)
    mn1 = min(mn1, nums[i] + i); // minimize for - ((a[i]+i) - (a[j]+j))

    // for eq2 find nums[i]-i considering the 3rd and 4th eqs
    mx2 = max(mx2, nums[i] - i);
    mn2 = min(mn2, nums[i] - i);
  }
  ans1 = mx1 - mn1;
  ans2 = mx2 - mn2;
  cout << " ans is " << max(ans1, ans2);
}

int main()
{

  return 0;
}
/*
For an unsorted array find max abs diff which is defined as |A[i] – A[j]| + |i – j| where |A| is the abs value of A. There is no constraint on
i and j values meaning any can be bigger or smaller than other

Here 4 cases arise -
a[i] > a[j] and i>j, => (a[i]-a[j]) + (i-j) = (a[i]+i) - (a[j]+j) => maximize this value
a[i] < a[j] and i<j => -(a[i]-a[j]) + -(i-j) = -(a[i]+i) + (a[j]+j) = - ((a[i]+i) - (a[j]+j)) => minimize this value as negative taken so smaller the better

a[i] > a[j] and i<j => (a[i]-a[j]) + -(i-j) = (a[i]-i) - (a[j]-j) => maximize this value
a[i] < a[j] and i>j => -(a[i]-a[j]) + (i-j) = -(a[i]-i) + (a[j]-j) = - ((a[i]-i) - (a[j]-j)) => minimize this value as negative taken

The first 2 have same ans with difference in sign but give same ans as abs taken and 3rd and 4th give the same ans as abs taken so we have to find the max
and min values for both nums[i]+i and nums[i]-i and subtract the min and max for the largest diff. abs() helps us making eq1 and 2 in 1 single ans
*/
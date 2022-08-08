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

void sol(vi nums, int n)
{
  // base case
  if (n < 3)
  {
    cout << " not possible";
    return;
  }
  
  sort(nums.begin(), nums.end()); // nlogn time
  int count = 0;
  // n^2 time
  for (int i = n - 1; i >= 2; i--)
  {
    int j = 0, k = i - 1;
    while (j < k)
    {
      if (nums[j] + nums[k] > nums[i])
      {
        count += k - j; // include all triangle from idx j to k as all valid bcos sorted
        k--;            // lowering the value for checking if we can find more triangles
      }
      else
        j++; // when nums[j]+nums[k]<=nums[i] so we find next bigger value to check
    }
  }
  cout << " ans is " << count;
}
int main()
{
  vi nums = {4, 3, 5, 7, 6}; // ans=3 [2,3,4] [2,4,5] [3,4,5]
  sol(nums, nums.size());
  return 0;
}

/*
For counting trinagles u can apply the 3 loop brute force where if nums[i] + nums[j] > nums[k] count++ but would be O(n^3)
Better way in n^2 would be to use 2 pointer approach using the same strategy
Consider [1,2,3,4,5] Start i from n-1 as nums[i] will be used as the third side as it would be easier to use that in the loop
and 2 variables j=0 and k=n-i-1 would start and we check nums[j] + nums[k] > nums[i]
For case j=0 it does not work as 1+4=5 is same as 5 so we do j++ but then at j=1 we have 2+4 > 5 which would mean all the combinations including j to k will
give the triangles and then we do k-- for finding more.
If 2 sum < 3rd then j++
*/
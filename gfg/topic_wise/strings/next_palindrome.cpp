// TODO: https://www.geeksforgeeks.org/next-higher-palindromic-number-using-set-digits/
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
  if (n <= 3)
    return; // 121 cannot be made bigger

  int mid = n / 2 - 1; // idx of ele in first half of num
  int i, j;
  // as we compare num[i+1], we don't want it to cross the upper limit
  for (i = mid - 1; i >= 0; i--)
  {
    if (nums[i] < nums[i + 1])
      break; // take the idx
  }

  // check if such digit exists
  if (i < 0)
  {
    cout << "not possible";
    return;
  }

  // now we use the i+1 idx as the val is larger
  int smallest = i + 1;

  // since we have to find the next palindrome on right of i+1, we find the smallest digit
  for (j = i + 2; j <= mid; j++)
  {
    if (nums[j] > nums[i] && nums[j] <= smallest)
    {
      smallest = j;
    }
  }

  swap(nums[i], nums[smallest]);

  swap(nums[n - i - 1], nums[n - smallest - 1]); // other side for palindrome
}

int main()
{

  return 0;
}
/*
this is similar to finding the next permutation where we first go to the mid ele and mid-1(as mid ele can be single) and from 0 to mid-1 find
first ele smaller than next or nums[i]<num[i+1] (consider 123... where 2<3 so we can swap 3 with 2 in it's palindrome) so only can we find the next bigger
by swapping
*/
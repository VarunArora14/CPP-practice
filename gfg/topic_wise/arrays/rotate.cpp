// https://www.geeksforgeeks.org/array-rotation/
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

void moveRight(vi &nums)
{
  int n = nums.size();
  int val = nums[n - 1];
  for (int i = n - 1; i > 0; i--)
  {
    nums[i] = nums[i - 1];
  }
  nums[0] = val;
}

// O(n*d)
void sol1(int d, vi &nums)
{
  int n = nums.size();
  d = d % n; // d can be more than n

  for (int i = 0; i < d; i++)
  {
    moveRight(nums);
  }
}

// Another method is to take a temp array and choose the d length part of array storing in temp, then we move all elements d pos right taking n time
// and at the end, we change the starting d elements replacing them with temp
void sol2(int d, vi &nums)
{
  int n = nums.size();
  d = d % n;

  vi temp(d); // can be max n
  for (int i = n - d, j = 0; i < n; i++, j++)
  {
    temp[j] = nums[i];
  }

  // move all ele d right
  for (int i = n - d; i >= 0; i--)
  {
    nums[i + d] = nums[i];
  }

  for (int i = 0; i < d; i++)
    nums[i] = temp[i];
}

int main()
{

  vi nums = {1, 2, 3, 4, 5, 6, 7};
  sol2(3, nums);

  for (int &i : nums)
    cout << i << " ";
  return 0;
}
// https://www.geeksforgeeks.org/majority-element/
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

int sol(vi &nums)
{
  int n = nums.size();
  if (n < 1)
    return -1;
  int count = 1, curr = nums[0];

  // count=2 at i=8 curr=1
  for (int i = 1; i < n; i++)
  {
    if (curr == nums[i])
      count++;
    else
      count--;

    if (count == 0)
    {
      curr = nums[i];
      count = 1;
    }
  }

  // check if candidate curr is the real winner with more than n/2 or not
  count = 0;
  for (int &i : nums)
  {
    if (i == curr)
      count++;
  }

  if (count > 2)
    return curr;
  else
    return -1;
}

int main()
{
  vi nums = {1, 2, 3, 1, 1, 11, 7, 1, 1}; // has to more than n/2 times not same
  int ans = sol(nums);
  cout << "ans is " << ans;
  return 0;
}
/*
ele occuring more than n/2 times is majority ele. For this we use the moore voting algo for which when we encounter an ele, we increase it's count if we
encounter it multiple times and if some other ele then count--. At the end we have a candidate and so confirm by checking it's count in array

Other solutions can be -
1. Brute force for each ele check it's occurence without sorting taking n^2 time and 1 space
2. Sort the vector in nlogn time and keep count++ as same ele encountered else count=1 and make check for count>n/2 after count++
3. maintain a map for storing the key as nums[i] and value as their occurences. At the end traverse map for finding count>n/2 take n space and n time
3. Moore voting which is above
*/
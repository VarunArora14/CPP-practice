// https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/
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

// Time here is O(k) as we go till k-- only
void sol1(vi nums1, vi nums2, int k)
{
  int n1 = nums1.size();
  int n2 = nums2.size();

  int i = 0, j = 0, ans = 0;

  // till either of them finishes
  while (i < n1 && j < n2)
  {
    if (nums1[i] <= nums2[j])
    {
      k--;

      if (k == 0)
      {
        ans = nums1[i];
        break;
      }
      i++;
    }
    else
    {
      k--;
      if (k == 0)
      {
        ans = nums2[j];
        break;
      }
      j++;
    }
  }

  while (i < n1)
  {
    k--;

    if (k == 0)
    {
      ans = nums1[i];
      break;
    }
    i++;
  }

  while (j < n2)
  {
    k--;
    if (k == 0)
    {
      ans = nums2[j];
      break;
    }
    j++;
  }

  cout << "ans is " << ans;
}

int main()
{
  // 1 2 3 4 5 7 8 9 11
  vi nums1 = {1, 3, 4, 8, 9};
  vi nums2 = {2, 5, 7, 11};

  sol1(nums1, nums2, 9);
  return 0;
}

/*
We could have used array with O(n1+n2) space
Other way could be using a priority queue(min heap) and pop k-1 ele so kth ele at the top

TODO: Look for the logK solution also using divide and conquer
*/
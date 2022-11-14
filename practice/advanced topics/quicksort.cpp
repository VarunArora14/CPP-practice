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

// keeps swapping to put elements smaller than pivot to left of nums[hi]/pivot
int part(vi &nums, int lo, int hi)
{
  int pivot = nums[hi];

  int i = lo - 1; // keeps track of next element to be filled if nums[j]<pivot

  for (int j = lo; j <= hi; j++)
  {
    if (nums[j] < pivot)
    {
      i++;
      swap(nums[i], nums[j]);
    }
  }
  swap(nums[i + 1], nums[hi]); // or pivot for putting that on correct idx

  return i + 1; // the idx of the pivot. All ele on left smaller than it and all on right bigger than it
}

void quicksort(vi &nums, int lo, int hi)
{
  if (lo < hi)
  {
    int pi = part(nums, lo, hi); // index of pivot, now we  do the same fn call for left and right

    quicksort(nums, lo, pi - 1);
    quicksort(nums, pi + 1, hi);
  }
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

  quicksort(nums, 0, n - 1);

  for (int num : nums)
    cout << num << " ";
  return 0;
}

/*
5
1 11 12 4 8
*/
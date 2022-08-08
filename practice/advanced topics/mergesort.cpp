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

void combine(vi &nums, int lo, int mid, int hi)
{
  int n1 = mid - lo + 1;
  int n2 = hi - mid;

  vector<int> l(n1), m(n2);

  for (int i = 0; i < n1; i++)
    cin >> l[lo + i];
  for (int j = 0; j < n2; j++)
    cin >> m[mid + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = lo;
}

void mergeSort(vi &nums, int lo, int hi)
{

  if (lo < hi)
  {
    // divide the array into 2 subarrays
    int mid = lo + (hi - lo) / 2;
    mergeSort(nums, lo, mid); // include mid as we have to put that in sorted too
    mergeSort(nums, mid + 1, hi);

    // reach till single element and then combine them as single ele always sorted

    combine(nums, lo, mid, hi);
  }
}

int main()
{

  int n;
  cin >> n;

  vi nums(n);

  for (int i = 0; i < n; i++)
    cin >> nums[i];

  mergeSort(nums, 0, n - 1);
  return 0;
}
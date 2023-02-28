#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <string>
#include <climits>
#include "initializer_list"

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define sz(x) ((long long)(x).size())
#define ppb pop_back
#define ff first
#define ss second

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpii = vector<pair<int, int>>;

const int mod = 1000000007;
int maxval = INT_MIN, minval = INT_MAX;

void abs_sort(vi nums)
{
  sort(nums.begin(), nums.end(), [](int &a, int &b)
       { return abs(a) < abs(b); });

  for (int num : nums)
  {
    cout << num << " ";
  }
}

int main()
{
  vi nums = {1, 2, -1, 4};
  abs_sort(nums);

  return 0;
}
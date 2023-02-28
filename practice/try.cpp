#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include "bitset"
#include <string>
#include "numeric"
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define F first
#define S second

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
bool digitCount(string num)
{

  int n = num.length();

  vector<int> vec(n);

  for (char ch : num)
  {
    int idx = ch - '0';
    vec[idx]++;
  }

  for (int i = 0; i < n; i++)
  {
    int val = num[i] - '0';
    if (val != vec[i])
      return false;
  }
  return true;
}
int main()
{
  int n = 7;
  vector<int> a = {4, 8, 1, 3, 2, 9, 11};

  vector<int> ind(n);
  iota(ind.begin(), ind.end(), 0);
  for (auto a : ind)
  {
    cout << a << " ";
  }
  cout << "\n";

  sort(ind.begin(), ind.end(), [&](int i, int j)
       { return a[i] > a[j]; });

  for (auto a : ind)
  {
    cout << a << " ";
  }
  cout << "\n";
}
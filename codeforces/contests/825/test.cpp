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

void solve()
{
  int n, k; // n is number of ele in that and k is point from where we are given the sequence
  cin >> n >> k;

  vector<long long> s(n + 1); // for prefix sum
  for (int i = n - k + 1; i <= n; i++)
  {
    cin >> s[i]; // get the prefix sum ele as input
  }

  if (k == 1)
  {
    cout << "YES\n";
    return;
  }

  vector<long long> a(n + 1); // array of numbers to find each ele from prefix
  // the first we can find is a[n-k+2] found by s[n-k+2] - s[n-k+1]
  for (int i = n - k + 2; i <= n; i++)
  {
    a[i] = s[i] - s[i - 1]; // s[n-k+2] - s[n-k+1]
  }

  // now we have found the sequence from a[n-k+2] to a[n-1], check if they are sorted or not as a[1]<=a2[2]<=..a[n] has to be followed as per ques
  if (!is_sorted(a.begin() + n - k + 2, a.end()))
  {
    // not sorted
    cout << "NO\n";
    return;
  }

  // Having checked that both an−k+2≤⋯≤an and sn−k+1≤(n−k+1)an−k+2 hold, we claim that the answer is "YES".
  // check if each prefix sum satisfies condition that s[n-k+1] <= a[i]*(n-k+1) as a[1]<=a[2]<=a[3]
  if (s[n - k + 1] > a[n - k + 2] * (n - k + 1)) // RHS should be bigger
  {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}
int main()
{
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
// here we are given prefix sum from n-k+1 to n where Sn-k+1 means sum of all ele from a[0] to a[n-k+1]
// to find the a[n-k+2] ele, we do s[n-k+2] - s[n-k+1]
// Another thing to note is that a1<=a2<=..an. if the ele do not staisfy this then ans in "NO"
// Also since it is sum of all ele till n-k+1 then (Si-k+1) / (i-k+1) = a[i]
// Note that the sum of the first n−k+1 elements of Ai should satisfy that Sn−k+1 = a1+⋯+an−k+1 ≤ (n−k+1)an−k+2. If this does not hold, the answer is "NO"
// as we have a1 to an in sorted order as in ques

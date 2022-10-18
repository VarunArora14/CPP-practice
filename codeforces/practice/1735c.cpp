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
  int n;
  cin >> n; // len of string
  string s;
  cin >> s;

  vector<bool> vis(26, false); // 'a' to 'z' stored from 0 to 25
  map<char, int> m1;
  int pos = 0; // pointing at 'A'

  for (char ch : s)
  {
    int idx = ch - 'a';
    if (!vis[idx])
    {
      // not visited then store
      vis[idx] = true;     // mark visited and store in adjacency of pos
      m1['a' + pos] = idx; // at given char store the index
      pos++;
    }
  }
  // now map stores character and it's corresponding mapped index of another char
  string ans = "";
  for (char ch : s)
  {
    char ele = m1[ch] + 'a'; // m1[ch] has idx and add 'a'
    ans += ele;
  }
  cout << ans << "\n";
}

int main()
{
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
// create an adjacency list for each char and for each char keep checking if it exists then use that otherwise create a new
// CODEFORCES => have a visited vector, vis['c']==false so vis['c']=true, adj['a'+i]='c', i++
// else vis['c']==true then adj['c'] is used in string
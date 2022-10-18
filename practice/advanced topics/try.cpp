#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include <unordered_set>

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

void func()
{
  unordered_set<int> us;

  us.insert(5);

  for (auto i : us)
    cout << i << " ";
}

void convert_str(vector<char> nums = {'1', '2', '3'})
{
  string str = "";
  for (int i : nums)
  {
    str += i;
  }
  cout << str;
}

int main()
{

  convert_str();
  return 0;
}
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

void count_bit(int n)
{
  int count = 0;
  while (n)
  {
    count += (n & 1);
    n = n >> 1;
  }
  cout << " count is " << count;
}

int main()
{
  int n = 13;
  count_bit(n);
  return 0;
}

/*
6 is 110 so number of set bits=2 and we have to count that
*/
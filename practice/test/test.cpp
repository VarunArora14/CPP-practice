#include <iostream>
#include <vector>
#include "unordered_map"
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n), b(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }

  unordered_map<int, int> m1, m2;

  for (int num : a)
  {
    m1[num]++;
  }

  for (int num : b)
  {
    m2[num]++;
  }

  for (auto [key, val] : m1)
  {
    if (m2.count(key) && m2[key] == val)
    {
    }
    else
    {
      cout << "False";
      return;
    }
  }

  cout << "True";
}
int main()
{

  solve();
}

// 1,2,3,4,5
// 3,4,2,1,5
#include <iostream>
#include "algorithm"
using namespace std;

int main()
{
  long key;
  cin >> key;
  int ans = 0;
  int a[10], n = 0;
  while (key != 0)
  {
    a[n++] = (key % 10);
    key = key / 10;
  }

  sort(a, a + n);

  int i = 0;
  while (a[i] == 0)
    i++;

  int temp = a[i];
  a[i] = a[0];
  a[0] = temp;

  i = 0;
  while (i < n)
  {
    ans = ans + a[i];
    ans = ans * 10;
    i++;
  }
  ans = ans / 10;
  cout << "\n"
       << ans;
  return 0;
}
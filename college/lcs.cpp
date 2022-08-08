#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
void print_lcs(char a[13], char b[13][13], int i, int j)
{
  if (i == 0 || j == 0)
  {
    return;
  }
  if (b[i][j] == 'D')
  {
    print_lcs(a, b, i - 1, j - 1);
    cout << a[i - 1];
  }
  else if (b[i][j] == 'U')
  {
    print_lcs(a, b, i - 1, j);
  }
  else
  {
    print_lcs(a, b, i, j - 1);
  }
}
int lcs_length(char a[], char b[])
{
  int lcs[13][13];
  char sym[13][13];
  int m = strlen(a);
  int n = strlen(b);
  int i, j;
  for (i = 0; i <= m; i++)
  {
    lcs[i][0] = 0;
  }
  for (j = 0; j <= n; j++)
  {
    lcs[0][j] = 0;
  }
  for (i = 1; i <= m; i++)
  {
    for (j = 1; j <= n; j++)
    {
      if (a[i - 1] == b[j - 1])
      {
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
        sym[i][j] = 'D';
      }
      else if (lcs[i - 1][j] <= lcs[i][j - 1])
      {
        lcs[i][j] = lcs[i][j - 1];
        sym[i][j] = 'L';
      }
      else
      {
        lcs[i][j] = lcs[i - 1][j];
        sym[i][j] = 'U';
      }
    }
  }
  cout << "\nLongest Common SubSequence is: ";
  print_lcs(a, sym, m, n);
  return lcs[m][n];
}
int main()
{
  char st1[10];
  char st2[10];
  cout << "\nEnter String1:";
  cin >> st1;
  cout << "\nEnter String2:";
  cin >> st2;
  int len = lcs_length(st1, st2);
  cout << "\nLength of longest Common Subsequence:" << len;
  return 0;
}
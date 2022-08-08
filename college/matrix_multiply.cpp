// for matrices of size m*n and p*q the condition is n==p and the resulting matrix is m*q

#include "iostream"
using namespace std;

int main()
{
  int a[100][100], b[100][100];
  int m, n, p, q;
  // input of first matrix
  cin >> m >> n >> p >> q;
  if (n != p)
  {
    cout << "the matrix does not satify the primary condition of columns of first = rows of second";
    exit(0);
  }
  int i, j, k;
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }
  for (i = 0; i < p; i++)
  {
    for (j = 0; j < q; j++)
    {
      cin >> b[i][j];
    }
  }
  int c[100][100] = {0}; // initialise all to 0

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < q; j++)
    {
      c[i][j] = 0;
      for (int k = 0; k < p; k++)
      {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < q; j++)
    {
      cout << c[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}

#include <iostream>

void func(char[], char[], int, int);
int main()
{
    int n, m;
    std::cout << "enter lengths";
    std::cin >> n >> m;
    char first[n], second[n];
    std::cout << "enter first - ";
    std::cin >> first;
    std::cout << "enter second - ";
    std::cin >> second;

    func(first, second, n, m);
}

void func(char first[], char second[], int n, int m)
{
    int k = 0;
    char final[20];
    int L[n + 1][m + 1];
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }

            else if (first[i - 1] == second[j - 1])
            {
                L[i][j] = 1 + L[i - 1][j - 1];
                final[k++] = second[j - 1];
            }
            else
            {
                L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    std::cout << L[n][m];

    std::cout << "\n \n The longest common subsequence is - ";
    for (i = 0; i < k; i++)
    {
        std::cout << final[i];
    }
}
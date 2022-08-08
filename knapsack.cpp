#include <iostream>

using namespace std;

int knapsack()
{
    int val[] = {6, 10, 12, 15};
    int len = sizeof(val) / sizeof(val[0]);
    int weight[] = {2, 3, 4, 5};
    int W = 5;

    int dp[len + 1][W + 1], i, j;

    for (i = 0; i <= len; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            else if (weight[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - weight[i - 1]]);
            }

            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (i = 0; i <= len; i++)
    {
        for (j = 0; j <= W; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[i][j];
}
int main()
{
    cout << knapsack();
}
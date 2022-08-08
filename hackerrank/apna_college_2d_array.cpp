#include <iostream>
using namespace std;
void matrix_search()
{
    int i, j, n, m, a[100][100];
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int ele;
    cin >> ele;
    // first is brute force i.e. linear search
    // Note  that in this matrix the rows are in ascending order from left to right and columns ascending from top to bottom
    // ex 1 4 7 11
    //    2 5 8 12
    //    3 6 9 16
    //    10 13 14 17

    /*
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == ele)
            {
                cout << ele << " found at i=" << i + 1 << " and j=" << j + 1;
                exit(0);
            }
        }
    }
    cout << "element not found";
    */
    //    Another method is moving left if element>a[i][j] and move down if element<a[i][j]
    // start from top right a[r][c]
    // if(a[r][c]==target) return true;
    //  else if(a[r][c]<target) r++;
    // else c--
    j = m - 1;
    i = 0;
    int count = 0;
    while (j >= 0 && i < n)
    {

        if (a[i][j] == ele)
        {
            cout << ele << " found at i=" << i + 1 << " and j=" << j + 1 << "\n";
            cout << "count is " << count;
            exit(0);
        }
        else if (a[i][j] < ele)
        {
            i++;
            // go down
        }
        else
        {
            j--;
            // move left to go to smaller element
        }
        count++;
    }
    cout << "element not found \n";
    cout << "count is " << count;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    matrix_search();
}
void multiply_matrix()
{
    // for multiply of matrix we need 2 of size n1*n2 and n2*n3 as columns of first=rows of second
    int i, j, n1, n2, n3, a[100][100], b[100][100];
    cin >> n1 >> n2 >> n3;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            cin >> a[i][j];
        }
    }
    for (i = 0; i < n2; i++)
    {
        for (j = 0; j < n3; j++)
        {
            cin >> b[i][j];
        }
    }
    int c[100][100]; // to store the multiplied values
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n3; j++)
        {
            c[i][j] = 0;
        }
    }
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n3; j++)
        {
            for (int k = 0; k < n2; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n3; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
}
void transpose_matrix()
{
    int i, j, n, m, a[100][100], b[100][100];
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    //  transpose of a matrix is when a[i] is replaced by a[j]
    // example 1 2 <--> 1 3
    //         3 4      2 4
    int temp = 0;
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < m; j++)
    //     {
    //         // cout << a[i][j] << " ";

    //         b[i][j] = a[j][i];
    //     }
    // }
    for (i = 0; i < n; i++)
    { // if j=0 then same as before and if j=i then transpose as upper triangle a[i][j]=a[j][i]
        // if swap all elements in matrix then we will get the same matrix  back
        for (j = 0; j < m; j++)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
void spiral_matrix()
{
    int i, j, n, m, a[100][100];
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    // for finding the spiral matrix we maiintain 4 variables row_start,row_end, col_start, col_end
    // spiral order logic
    int row_start = 0, row_end = n - 1, col_start = 0, col_end = m - 1;
    while (row_start <= row_end || col_start <= col_end)
    {
        // for row_start
        for (int col = col_start; col <= col_end; col++)
        {
            cout << a[row_start][col] << " ";
        }
        row_start++;

        // for col_end
        for (int row = row_start; row <= row_end; row++)
        {
            cout << a[row][col_end] << " ";
        }
        col_end--;

        // for row_end
        for (int col = col_end; col >= col_start; col--)
        {
            cout << a[row_end][col] << " ";
        }
        row_end--;

        // for col_start
        for (int row = row_end; row >= row_start; row--)
        {
            cout << a[row][col_start] << " ";
        }
        col_start++;
    }
}
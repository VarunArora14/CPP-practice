#include <iostream>
#include <climits>
using namespace std;
void pairsum()
{
    // Take an array and k and find pair of elements who sum=k
    int n, k, i, j;
    cin >> k >> n;
    int a[100];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    /*
    This is brute force with time n^2
    int e1, e2;
    for (i = 0; i < n; i++)
    {
        e1 = a[i];
        for (j = i + 1; j < n; j++)
        {
            if (k - e1 == a[j])
            {
                e2 = a[j];
                cout << "the pair is " << e1 << " and " << e2;
                exit(0);
            }
        }
    }
    */

    // Now we can also do it in n time. Also, know that input array is sorted and if not then sort it first
    // Then  we maintain a low and high pointer marking the start and end of array
    // 2 4 7 11 14 16 20 21
    // ^                 ^
    // |                 |
    // low              high
    int high = n - 1, low = 0;
    // On sorted array
    for (i = 0; i < n; i++)
    {
        if (a[high] + a[low] < k)
        {
            low++;
        }
        else if (a[high] + a[low] == k)
        {
            cout << "the pairs are " << a[high] << " and " << a[low];
            exit(0);
        }
        else
        {
            high--;
            // as a[high]+a[low]>k so reduce high to go to lower number
        }
    }
    cout << "no pair found";
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    pairsum();
}
/*
int kadane(int a[], int n)
{
    int currsum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currsum += a[i];
        if (currsum < 0)
        {
            currsum = 0;
        }
        maxsum = max(maxsum, currsum);
    }
    return maxsum;
}
void circular_subarray()
{
https: //www.youtube.com/watch?v=0JYgnhnZFcE&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=25&t=623s
    int i, j, k, sum = 0, fsum = 0;
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int wrapsum, nonwrapsum;
    nonwrapsum = kadane(a, n); // find it using kadane algo
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += a[i];
        a[i] = -a[i];
    }
    wrapsum = totalsum + kadane(a, n); // totalsum - - kadane(a,n)
    cout << max(wrapsum, nonwrapsum) << "\n";
    // for (i = 0; i < n; i++)
    // {
    //     sum = 0;
    //     for (j = i; j < n; j++)
    //     {
    //         sum += a[j];
    //         // cout << "sum is " << sum << "\n";
    //         max_sum = max(max_sum, sum);
    //     }
    //     // cout << "sum is " << sum << "\n";
    // }
    // cout << "max sum is " << max_sum;
}
*/

// void max_subarray_sum()
// {
//     int i, j, k, sum = 0, fsum = 0;
//     int n, a[100];
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     /*

//     for (i = 0; i < n; i++)
//     {
//         for (j = i; j < n; j++)
//         {
//             sum = 0;
//             for (k = i; k <= j; k++)
//             {
//                 // cout << a[k] << " ";
//                 sum = sum + a[k];
//             }
//             // cout << "\n";
//             fsum = max(fsum, sum);
//              This is brute force method, time is n^3
//         }
//     }
//     cout << "max sum is " << fsum;
//     */

//     // This is unsure if fully correct

//     int max_sum = 0;
//     for (i = 0; i < n; i++)
//     {
//         sum = 0;
//         for (j = i; j < n; j++)
//         {
//             sum += a[j];
//             // cout << "sum is " << sum << "\n";
//             max_sum = max(max_sum, sum);
//         }
//         // cout << "sum is " << sum << "\n";
//     }
//     cout << "max sum is " << max_sum;
//     /*
//     //    Another approach is cumulative sum array
//     int cum_arr[100];
//     cum_arr[0] = 0;
//     for (i = 1; i <= n; i++)
//     {
//         cum_arr[i] = cum_arr[i - 1] + a[i - 1];
//     }
//     int max_sum = INT_MIN;
//     for (i = 1; i <= n; i++)
//     {
//         int sum = 0;
//         for (int j = 0; j < i; j++)
//         {
//             sum = cum_arr[i] - cum_arr[j];
//             max_sum = max(sum, max_sum);
//         }
//     }
//     cout << "max sum is " << max_sum;
//     */
// }

/*
void smallest_positive()
{
    int n;
    cin >> n;
    int a[200000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Given array -10^6 < a[i] < 10^6 so make 2 x 10^6 array
    bool check[100000] = {false};
    // since a[i] varies to 10^6, make array check of same size and when a[i]>0 then put check[a[i]]=true
    // example- a[i]= -9 1 4 2, check[]= F F F F F. Now, as a[i]=1 is present do check[a[i]] or check[1]=T. So now  check array is
    // check[]= F T T F T F. first is false as element 0 and in array the 3rd position is false. Now iterate the check array to find the first false
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            check[a[i]] = true;
        }
    }
    // starting with 1 as we dont need to count 0 as positive number
    for (int i = 1; i < n; i++)
    {
        if (check[i] == false)
        {
            cout << "position is " << i << "\n";
            break;
        }
    }
}
*/

// void contiguous_subarray()
// // ** important
// {
//     int i = 0, j = 0, s, n, a[100000];
//     cin >> s >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     // i = 0;
//     // i is 5 after the above loop
//     /*
//     BRUTE FORCE
//     int fpos = 0, lpos = 0, sum = 0;
//      we start from 0 and see when we get the subarray value. We need to move a window of values
//      s=5, a[]= {1,1,0,4,5}
//     for (i = 0; i < n; i++)
//     {
//         sum = 0;
//         lpos = fpos = i;
//         for (j = i; j < n; j++)
//         {
//             if (sum == s)
//             {
//                 fpos = j;
//                 cout << "start is " << lpos + 1 << " and end is " << fpos;
//                 // not fpos+1 as we check in the next iteration whether the sum is same or not
//                 exit(0);
//                 // break;
//             }
//             else if (sum < s)
//             {
//                 sum = sum + a[j];
//                 fpos++;
//                 cout << "sum is " << sum << "\n";
//             }
//             else
//                 break;
//         }
//     }
//     cout << "start is " << lpos << " and end is " << fpos;
//     */
//     // cout << "i is " << i << " j is " << j << "\n";
//     int st = -1, en = -1, sum = 0;
//     // make sure here both i and j=0
//     while (j < n && sum + a[j] <= s)
//     {
//         sum += a[j];
//         j++;
//     }
//     if (sum == s)
//     {
//         cout << i + 1 << " " << j << "\n";
//     }
//     while (j < n)
//     {
//         sum += a[j];
//         while (sum > s)
//         {
//             sum -= a[i];
//             i++;
//         }
//         if (sum == s)
//         {
//             st = i + 1;
//             en = j + 1;
//             break;
//         }
//         j++;
//     }
//     cout << st << " " << en;
// }

/*
void themepark()
{
    int n, t;
    // cin >> t;
    // test cases
    cin >> n;
    int v[100];
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int rday = 0, maxnum = 0;
    if (n == 1)
    {
        cout << "record breaking days are 1";
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (v[i] > v[i + 1])
                {
                    rday++;
                }
            }
            else
            {
                if (v[i] > maxnum)
                {
                    if (i == n - 1 || v[i] > v[i + 1])
                    {
                        rday++;
                    }
                }
            }
            maxnum = max(v[i], maxnum);
        }
        cout << "record breaking days are " << rday;
    }
}
*/
/*
void subarray()
{
    int n, a[100];
    cin >> n;
    int i, j;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int len = 1, diff = 0, flen = 1;
    diff = a[1] - a[0];
    for (i = 2; i < n; i++)
    {
        if (diff == (a[i] - a[i - 1]))
        {
            len++;
            // cout << "hello ";
        }

        else
        {
            diff = a[i] - a[i - 1];
            // cout << "diff is " << diff << "\n";

            len = 1;
        }
        flen = max(flen, len);
    }
    cout << "max length is " << flen + 1;
    // +1 because for subarray 2 2 2 the common diff is 0  which is coming  2 times but total numbers are 3
}

*/
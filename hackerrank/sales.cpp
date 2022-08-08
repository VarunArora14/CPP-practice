// https://www.hackerrank.com/challenges/sock-merchant/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> nums;
    int n, input;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        nums.push_back(input);
    }
    sort(nums.begin(), nums.end());
    int count = 1, pairs = 0, first = nums[0];
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i < n; i++)
    {
        if (first == nums[i])
        {

            count++;
            cout << "here nums[i] is " << nums[i] << "and count is " << count << "\n";
        }
        else
        {
            pairs += count / 2;
            count = 1;
            first = nums[i];
        }
    }
    cout << "pairs are " << pairs;
}
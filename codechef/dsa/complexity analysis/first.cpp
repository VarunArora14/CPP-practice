#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    vector<int> num;
    int n, item;
    cin >> n;
    for (auto i = 0; i < n; i++)
    {
        cin >> item;
        num.push_back(item);
    }
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == 42)
            break;
        cout << num[i] << " ";
    }
}
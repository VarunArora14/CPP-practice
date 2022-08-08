// https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/make-all-equal-90a21ab2/
/*

#include <iostream>
#include <algorithm>
#include <vector>
// for std::max
using namespace std;
void steps(int n, int a[], int b[]);
int check(int n, int a[]);
// remember when return vector then define the <int> thing in initialisation
int findmax(int n, int a[], int b[])
{
    int big = 0, pos = 0;

    for (int i = 0; i < n; i++)
    {
        if (big < a[i])
        {
            big = a[i];
            pos = i;
        }
    }
    return pos;
}
// int count = 0;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, i;
    cin >> n;
    int a[n], b[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    steps(n, a, b);
    // Take the largest element along with the index of the element and do a[i]-b[i] till all elements are same
    // Assuming all numbers are positive, if any a[i]-b[i] goes < 0 then return -1 else keep a count of subtractions
    // make a check() function for seeing whether all elements are same or not. If same then print count
}

int check(int n, int a[])
{

    int i = 1, num = a[0], flag = 1;
    // cout << num << " is num ";
    if (num < 0)
    {
        cout << "hello 53 ";
        cout << "no. of steps are -1";
        exit(0);
        return -1;
    }

    while (i < n)
    {
        if (a[i] < 0)
        {
            cout << "no. of steps are -1";
            exit(0);
            return -1;
            break;
        }

        if (num != a[i])
        {
            flag = 0;
            break;
        }
        i++;
    }
    if (flag == 1)
    {
        cout << " total steps taken are ";
        return 1;
    }
    // if flag=0 continue with the a[i]-b[i] else print the count
    return 0;
}

void steps(int n, int a[], int b[])
{
    // cout << "hello";
    int count = 0;
    if (n == 0)
        cout << " 0 steps";

    else if (check(n, a) == 0)
    {

        while (check(n, a) == 0)
        {
            int i = findmax(n, a, b);
            // v[0] is position/i
            // v[1] is num/big
            a[i] = a[i] - b[i];
            count++;
        }
    }
    else
    {
        cout << " no of steps are " << count;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
*/
#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int main()
{

    int n;

    cin >> n;

    vector<int> a(n);

    vector<int> b(n);

    vector<int> minElements;

    for (int i = 0; i < n; i++)

        cin >> a[i];

    for (int i = 0; i < n; i++)

        cin >> b[i];

    int min = *min_element(a.begin(), a.end()); //finds the minimum element in vector a and stores it in variable min

    minElements.push_back(min);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == min)
        {

            while (min > b[i] && b[i])
            { //it's important to consider this possibility of b[i]=0, it's not mentioned in constraints but can give error here

                min = min - b[i];

                minElements.push_back(min); //storing all possible minima in vector minElements

            } // while ends

            break;

        } // if ends

    } // for ends

    int steps;

    for (int min : minElements)
    {

        steps = 0;

        for (int i = 0; i < n; i++)
        {

            if (a[i] == min)

                continue;

            else
            {

                int diff = a[i] - min; //diff stores how much far is the current element to the element that we have to converge i.e min

                if (diff % b[i] == 0) // if diff is a multiple of b[i] then we can converge to this minima

                    steps += diff / b[i];

                else
                { // if diff is not a multiple of b[i] then we cannot converge to  this minima, therefore, steps=-1

                    steps = -1;

                    break;
                }
            }
        }

        if (steps != -1)
        {

            break;
        }
    }

    cout << steps;

    return 0;
}
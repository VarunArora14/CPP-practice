// Rotating arrays
#include <iostream>
#include <stdlib.h>

using namespace std;

void left1(int[], int);
void right1(int[], int);

int main()
{
    cout << "enter the size";
    int n, i;
    cin >> n;
    cout << "enter the array ";
    int a[50];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    char ch = 'y';
    do
    {
        system("cls");
        cout << " 1. left shift" << endl
             << " 2. right shift" << endl
             << " Enter choice " << endl;
        //for rotating make the first element the last and shift the array towards the old position
        // of start
        /*
[2 , 3 , 4 , 5] -> [3 , 4 , 5 , 2] => left shift
[2 , 3 , 4 , 5] -> [5 , 2 , 3 , 4] => right shift
*/
        int p;
        cin >> p;
        switch (p)
        {
        case 1:
            left1(a, n);
            break;

        case 2:
            right1(a, n);
            break;

        default:
            cout << "no such option " << endl;
        }
        cout << "Continue ? ";
        cin >> ch;
    } while (ch == 'y');
}

//left shift
void left1(int a[], int n)
{

    cout << "enter the no. of times left shift of array ";
    int x,i,j, temp = 0;
    cin >> x;
    for (i = 0; i < x; i++)
    {
        temp = a[0];
        cout << "temp " << temp << endl;
        for (j = 0; j < n - 1; j++) // n-1 as j+1 for n would be after the sze of the array
        {
            a[j] = a[j + 1];
        }
        a[j] = temp; // not temp=a[j]
    }
    cout << endl
         << "the array is";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

// right shift

void right1(int a[], int n)
{
    int temp;
    cout << "enter the no. of times right shift of array ";
    int y, i, j;
    cin >> y;
    for (i = 0; i < y; i++)
    {
        temp = a[n - 1];
        cout<<"temp "<<temp<<endl;
        for (j = n - 1; j > 0; j--)
        {
            a[j ] = a[j-1];
        }
        a[j] = temp;
    }

    cout << endl
         << "the array is";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

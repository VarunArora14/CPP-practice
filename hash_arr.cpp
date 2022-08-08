#include <iostream>
#include <process.h>
/*
This is code for linear probing in open addressing. If you want to do quadratic probing
and double hashing which are also open addressing methods in this code when I used hash
function that (pos+1)%hFn in that place just replace with another function.
*/
using namespace std;

// HASHING USING ARRAYS

void insert(int a[], int n, int s)
{
    int ele, pos, c = 0;
    cout << "enter the element";
    cin >> ele;
    pos = ele % n;
    // INT_MIN and INT_MAX indicates that cell is empty. So if cell is empty loop will break
    // and goto bottom of the loop to insert element
    while (a[pos] != INT32_MIN)
    {
        if (a[pos] == INT32_MAX)
            break;
        pos = (pos + 1) % n;
        c++;
        if (c == s)
            break;
    }
    if (c == s)
        cout << "The table is full";
    else
    {
        a[pos] = ele;
        // c++;
    }
}

void del(int a[], int n, int s)
{
    /*
	very careful observation required while deleting. To understand code of this delete
     function see the note at end of the program
	*/

    int ele, pos, c = 0;
    cout << "enter element to be deleted";
    cin >> ele;
    pos = ele % n;
    cout<<"pos is "<<pos<<" ele is "<<ele<<" n is "<<n<<endl;
    // first we search for the ele from function and then move linearly as it is through linear
    // probing method
    while (c++ != s)
    {   cout<<"hello "<<endl;
        if (a[pos] == INT32_MIN) //empty location from fn position meaning not present
        {
            cout << "Not present in the table";
            
            break;
        }
        else if (a[pos] == ele)
        {
            a[pos] = INT32_MAX; //to make sure that it was deleted and not empty - tombstone
            break;
// without break multiple times fn run and showing not present element even though it deleted
        }
        else
        {
            pos = (pos + 1) % ele;
        }
    }

    if (--c == s) // coming from while condition of total wrap around table
    // not n but c
        cout << "not found in hashtable";
}

void search(int a[], int n, int s)
{
    int ele, pos, c = 0, i, flag = 0;
    cout << "enter the size";
    cin >> ele;
    pos = ele % n;
    while (c++ != s)
    {
        if (a[pos] == INT32_MIN)
        {
            cout << "not found in hash table";
            break;
        }
        else if (a[pos] == ele)
        {
            cout << a[pos] << " found at position " << pos + 1;
            flag = 1;
        }
        else
        {
            if (a[pos] == INT32_MAX || a[pos] != INT32_MIN)
                pos = (pos + 1) % n;
        }
    }

    if (flag == 0)
        cout << "element not found";
    if (--n == s)
        cout << "element not found1";
}

void disp(int a[], int n, int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        cout << a[i] << " at position " << i << endl;
    }
}

int main()
{
    int s;
    cout << "enter size";
    cin >> s;
    int a[s];
    cout << "enter hash function(k mod n) - n";
    int n, i, x;
    cin >> n;

    for (i = 0; i < s; i++)
    {
        a[i] = INT32_MIN;
    }
    char ch = 'y';
    do
    {
        cout << endl
             << "1. Insertion" << endl
             << "2. Delete" << endl
             << "3. Search" << endl
             << "4. Display"
             << "Exit" << endl
             << endl
             << "Choose - " << endl;
        cin >> x;

        switch (x)
        {
        case 1:
            insert(a,n,s);
            break;

        case 2:
            del(a, n, s);
            break;

        case 3:
            search(a, n, s);
            break;

        case 4:
            disp(a, n, s);
            break;
        case 5:
            exit(0);
        default: cout<<"not such option";
            break;
        }
cout<<endl<<"continue ? ";
cin>>ch;
    } 
    while (ch=='y');
}
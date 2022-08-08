#include <iostream>
#include <list>

using namespace std;

class hash1
{
private:
    /* data */
    int val;
    list<int> *table;

public:
    hash1(int a);
    int hashfunc(int x);
    void insert(int a);
    void disp();
    void del(int);
    // ~hash();
};

hash1::hash1(int a)
{
    this->val = a;
    table = new list<int>[val];
}
int hash1::hashfunc(int x)
{
    return (x % val);
}

void hash1::insert(int a)
{
    int h = hashfunc(a);
    table[h].push_back(a);
    //pushing element a in h
}

void hash1::disp()
{
    for (int i = 0; i < val; i++)
    {
        cout << i;

        for (auto x : table[i])
        {
            cout << "-->" << x;
        }
        cout << endl;
    }
}

void hash1::del(int a)
{
    int hashval = hashfunc(a);
    list<int>::iterator i;
    for (i = table[hashval].begin(); i != table[hashval].end(); i++)
    {
        if (*i == a)
        {
            break;
        }
    }
    if (i != table[hashval].end())
    {
        table[hashval].erase(i);
    }
}
int main()
{

    cout << "enter hash function 'k' for n%k ";
    int k = 7;
    cin >> k;
    // array that contains keys to be mapped
    int a[] = {15, 11, 27, 8, 12, 37, 51};
    int n = sizeof(a) / sizeof(a[0]);
    hash1 h(k);
    //first create the object and then work on it

    for (int i = 0; i < n; i++)
    {
        h.insert(a[i]);
    }
    //inserting items inside hashtable

    // h.del(12);
    //delete item

    h.disp();
}
#include <iostream>
#include <list>
using namespace std;

//NOT name class as hash because hash is a template created already
class hash1
{
private:
    int BUCKET;
    list<int> *table; // creating list of pointers named table of type int
    
public:
    hash1(int v);
    void insert(int key);
   // int search(int x);
    void del(int k); //key
    int hashfunc(int x)
    {
        return (x % BUCKET);
    }
    void disp();
};

hash1::hash1(int v)
{
    //constructor to initialise list and this->bucket value
    this->BUCKET = v;
    table = new list <int>[BUCKET];
}

void hash1::insert(int key)
{
    int h;
    h=hashfunc(key);
    table[h].push_back(key); //pushing element at next of the previous element of list
}

void hash1::del(int key)
{
    int h=hashfunc(key);
    //find key in (index)th list
   list <int>::iterator i;
   for(i=table[h].begin();i!=table[h].end();i++)
   {
       if(*i==key)
       break;
   }
   //if key found in table then delete it
   if(i!=table[h].end())
   {
       table[h].erase(i);
   }
}
void hash1::disp()
{
    for (int i = 0; i < BUCKET; i++){
      cout << i;
      for (auto x:table[i])
      cout << " --> " << x;
      cout << endl;
    }
}

int main()
{
    cout<<"enter size";
    int s,i,a[20];
    cin>>s;
    hash1 h(7);//implicit argument 11 to constructor making bucket value 7 and initialise list
    cout<<endl<<"enter array";
    for(i=0;i<s;i++)
    {
        cin>>a[i];
        h.insert(a[i]);
    }
    h.del(a[2]);//3rd ele
    h.disp();
    return 0;

}


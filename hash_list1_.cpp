#include <iostream>
#include <process.h>
const int S = 31;
//OPEN ADDRESSING LINKED LISTS
using namespace std;
//1
class hashtable
{
public:
int k;
int v;
    hashtable(int k, int v);
};

hashtable::hashtable(int k, int v)
{ //2
    this->k = k;
    this->v = v;
}
//3

class hash1
{
private:
    hashtable **t; //4
public:
    hash1();
    ~hash1(); // deallocate memory

    int hashfunc(int k) // k is key and our function is key mode size
    {
        return k % S;
    }

    void insert(int k, int v);
    int search(int k);
    void del(int k);
};

hash1::hash1()
{
    t = new hashtable *[S];
    //5

    for (int i = 0; i < S; i++)
    {
        t[i] = nullptr;
    }
}

void hash1::insert(int k, int v)
{
    int h;
    h = hashfunc(k);                        //6
    while (t[h] != nullptr && t[h]->k != k) // till any of the conditions met
    {
        h = hashfunc(h + 1); // open addressing
    }
    if (t[h] != nullptr) //if not null that means memory leak or some problem
        delete t[h];

    t[h] = new hashtable(k, v);
    //above is creating object t[h] of class hashtable in which then the constructor would
    //allocate values of key-k and value-v with help of this pointer to remove ambiguity
}

int hash1::search(int k)
{
    int h=hashfunc(h);
    while(t[h]!=nullptr && t[h]->k!=k)
        h=hashfunc(h+1);

        if(t[h]==nullptr)
        return -1;
        else 
        {
            return t[h]->v;
        }
}

void hash1::del(int k)
{
int h=hashfunc(k);
while(t[h]!=nullptr)//till end
{
if(t[h]->k==k) // t[h] pointing to key k has value k condition
break;//come out of loop
h=hashfunc(h+1);
}
if(t[h]==nullptr)
cout<<"no element found at that key "<<k<<endl;
else
{
    delete t[h];
}
cout<<"Element deleted"<<endl;
}

hash1::~hash1()
{
    for(int i=0;i<S;i++)
    {
        if(t[i]!=nullptr)
        delete t[i];
        delete[] t;

    }
}


//7

int main()
{
    hash1 hash;//object of hash1 - hash
    int k, v;
   int c;
   while (1) {
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Enter element to be inserted: ";
            cin>>v;
            cout<<"Enter key at which element to be inserted: ";
            cin>>k;
            hash.insert(k, v);
         break;
         case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>k;
            if (hash.search(k) == -1) {
               cout<<"No element found at key "<<k<<endl;
               continue;
            } else {
               cout<<"Element at key "<<k<<" : ";
               cout<<hash.search(k)<<endl;
            }
         break;
         case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>k;
            hash.del(k);
         break;
         case 4:
            exit(1);
         default:
            cout<<"\nEnter correct option\n";
      }
   }

}

/*
1

We cannot initialise values inside the class because 
1. variable will have value for which memory is needed which cant happen until
 objects initialised 
2.  you will have a value even though you don't have any object but what does it represents?
That's why constructors are there to help us so that we can initialze the instances
 whenever it is legitimate to do so...
If the kind of initialization you are thinking of start happening what would you achieve 
with that it will be completed useless...

Hence, when you define a class you don’t actually allocate memory so there is no scope of 
initializing a variable instead memory is allocated when you declare an object of that 
class and that is when you should initialize your variable of the class. Each object 
could have either same or different values of the variables.
*/

//2
// to remove ambiguity for each object as functions are stored as single copy
// and no different memory allocations for diffrent object functions.

/*

3
We needed another table as 1 is for declaring the hash table of size S which stores the 
index and then their indexes or keys would be computed for the hash function in functions
of class hash1. Making a class was necessary as constructors and more organized look.
*/

//4
// double pointer means pointer to a pointer which is because it will point
// to nodes of list which would point to the chained lists made for collisons

/*
    5
    
    This a double pointer pointing to the array of hashtable pointers
    - dynamic array of size S of pointers to hashtable class

    It is a way of creating pointer array to hashtable which would contain keys or indices
    which would point to the linked list


    Now, putting null on all values of t[] as they would be memory leaks instead.
    for more - code snippets -> pointer-alloc
    */

//6 stores hash function value
// here t[h] is pointing towards pointer at key k
// like node->next where node was pointing to next pointer and checks whether present
//or not

/*
7

Size preferably prime and not a power of 2 or near to it as it shows similar pattern of
same allocation of bits on same key with last k bits for table of size 2^k.
if k=4 then last 4 bits only considered and rest all with same last 4 bits are
put under the same key which is a huge problem especially something like phone numbers.
So, preferably size of table m or S should be prime and not near power of 2. 
*/

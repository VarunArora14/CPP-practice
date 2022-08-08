#include<iostream>
#include<map>

using namespace std;

int main()
{   
    // empty map container
    map<int,int> newmap;

    newmap.insert(pair<int,int>(1,10));
    // entering elements in random order where first paramater is key and second value

    newmap.insert(pair<int,int>(3,30));
    newmap.insert(pair<int,int>(2,20));

    // Does not repeat the old values
    newmap.insert(pair<int,int>(2,40));
    newmap.insert(pair<int,int>(4,50));
    newmap.insert(pair<int,int>(5,60));
    newmap.insert(pair<int,int>(6,70));

    // Declaring a map iterator
    map<int,int>::iterator itr;

    cout<<"The map newmap is \n";
    for(itr = newmap.begin();itr!=newmap.end();itr++)
    {
        cout<<itr->first<<" "<<itr->second<<"\n";
    }

    // Assigning elements from newmap to newmap1
    map<int,int> newmap1(newmap.begin(),newmap.end());


    // Now removing an element using the erase function which can work in 3 ways
    // 1. Erasing by entering the key to erase
    // map_name.erase(key) -> 
    // newmap.erase(5);

    // 2. Erasing a position
    // map_name.erase(iterator position)
    //  auto it = mp.find(2); 
    // mp.erase(it); 

    //3. Erasing for a given range
    // map_name.erase(iterator position1, iterator position2)

    // position1 – specifies the iterator that is the reference to the element from which 
    // removal is to be done.
    // position2 – specifies the iterator that is the reference to the element upto which 
    // removal is to be done

    // auto it1 = mp.find(2); 
    // auto it2 = mp.find(5); 
    // mp.erase(it1, it2);

    // Removing all the elements in the list till key value 3

    cout<<"\n\n The new map is \n";
    newmap1.erase(newmap1.begin(),newmap1.find(3));

     for(itr = newmap1.begin();itr!=newmap1.end();itr++)
    {
        cout<<itr->first<<" "<<itr->second<<"\n";
    }

     // remove all elements with key = 4 
    // int num; 
    // num = newmap1.erase(4); 
    //   cout << num << " removed \n"; 
    //   The output would be 1 as 1 key has key value=4


}
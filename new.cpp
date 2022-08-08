
#include<iostream>
#include<vector>

using namespace std;

class heap
{
  int size;
  vector<int> vect ={-1};//arbitrary value assigned -1 for first element vect[0] not useful
  // only 1 to n elements as from root to end and then operations
  int p(int i)//parent
  {
    return i>>1;  //i/2
  }
  int l(int i)
  {
    return i<<1;  //2*i
  }
  int r(int i)
  {
    return (i<<1)+1; // 2*i+1
  }

  public:
  bool isempty() const
  {
    return size==0; }
  int getmax () const // const as always the first element
  {
    return vect[1];
  }
  void insert(int val);
  void extractmax();// take out max element in max heap which then need to be heapified
  void heapifyup(int i);
  void heapifydown(int i);


};
/*
for insertion we have to first cheeck whether size os valid or not and then we enter an item
most probably at the end of the heap and then then we heapify upwards. 
*/
void heap::insert(int val)
{
  // we push back 0 at the end, increment the size and then put the value there
  //change to just vect.push(val)
  if(size+1 >= vect.size())
  {
    vect.push_back(0);
  }
  vect[++size]=val;
  heapifyup(size);
  // the added val at position size
  }

void build(int a[] , int n);
void maxheapify(int a[] ,int i ,int n);
int count=0;
int main()
{
  int a[]={16,4,10,14,7,9,3,2,8,1};
  	int n = sizeof(a) / sizeof(a[0]); 
  build(a,n);
  cout<<endl<<"the new heap is "<<endl;
  for(int i=0;i<10;i++)
  {
    cout<<a[i]<<" ";
  }

}
//int count=0;

void build(int a[], int n)
{ 
  int start=(n/2)-1;
 for(int i=start;i>=0;i--)
 {  cout<<count++;
  // cout<<endl<<count++<<"at i="<<i<<" now heap is "<<endl;
    maxheapify(a,i,n);
   // for(i=0;i<n;i++)
   // {cout<<a[i]<<" ";}
}
}
  

/*
All problems arised due to initialisation of value of l and r which led to build fn infinite loop
an no answer too. Solution was change value of l initialised from 2*i to 2*i+1 and right to
2*i+1 to 2*i+2
*/

void maxheapify(int a[] , int i ,int n)
{
  int l,r,large;
   int t;
  large=i;
  //l=left(i);
  l=(i<<1)+1;
  //r=right(i);
  r=(i<<1)+2;
  if(l<n && a[l]>a[i])
  {
    large=l;
  }
 // else large=i;
  if(r<n && a[r]>a[large])
{
  large =r;
}
if(large!=i)
{
 
 // t=a[i];
  //a[i]=a[large];
  //a[large]=t;
  swap(a[i],a[large]);
  maxheapify(a,large,n);
}
}

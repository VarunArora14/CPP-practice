/* fns are

    1. getMax() - gets the root of the element
    2. extractMax() - extracts the root of the element but maintains the heap property O(log n)
    3.  Decreases value of key. The time complexity of this operation is O(Logn).
        If the decreases key value of a node is less than the parent of the node,
        then we don’t need to do anything. Otherwise, we need to traverse up to fix the
        violated heap property.
    4. insert() -  Inserting a new key takes O(Logn) time. We add a new key at the end of
                the tree. IF new key is less than its parent, then we don’t need to do anything.
                   Otherwise, we need to traverse up to fix the violated heap property.

    5. delete(): Deleting a key also takes O(Logn) time. We replace the key to be deleted with
                 minum infinite by calling decreaseKey(). After decreaseKey(), the minus
                  infinite value must reach root, so we call extractMin() to remove the key.
                  */
#include<iostream>
//#include<>

using namespace std;

int left(int i)
{
  return 2*i;
}
int right(int i)
{
  return 2*i+1;
}
void build(int a[] , int n);
void maxheapify(int a[] ,int i ,int n);
int main()
{
  int a[]={16,4,10,14,7,9,3,2,8,1};
  build(a,10);
  cout<<endl<<"the new heap is "<<endl;
  for(int i=0;i<10;i++)
  {
    cout<<a[i]<<" ";
  }

}
/*It checks for nodes whether greater than children and then swaps them
pseudo code is -

for(i=n/2 downto 1)
maxheapify(A,i); -> it takes O(logn)

Now the intial simple complexity may give an assumption that it takes log2N*N time but
looking at operations per node gives another analysis and values as shown below.

This functio is used for building heap which first moves from the bottom up mannner in wich
N/2 nodes are already children so we ignore them as they are already max heaps and then move
to level 1 from bottom which has N/4 nodes and then N/4 nodes remaining above. For those N/4
nodes N/4.1.c time takes place as 1 level so 1 swap and c is constant time.
Similarly next N/8 nodes take N/8.2.c time as 2 levels so max 2 swaps so on till 1.log2 N.c
time as root node only with logN max swapping where logN is height of the tree as we suppose
left and right subtrees are binary trees. Adding them
N/4.1.c + N/8.2.c +... 1.log2 N.c =
(assuming N/4 = 2^k)
2^k.c.(1/2^0 + 2/2^1 + 3/2^3... (k+1)/2^k) -> again k is height of tree and 2^k=N/4

Since inner series is convergent because it is in form of i=0 to n (i+1/2^i) which can be
proved converegent by induction or tests.
Since it is bounded as convergent, it has max value < 3 as first 2 terms add=2 and then next
terms value<1. So now, it has value c'.
Time complexity now is, c.2^k.c' = C.2^k where 2^k=N/4 -> O(CN) = O(N)
*/
void build(int a[], int n)
{
  for(int i=n/2;i>=0;i--)
  { cout<<endl<<"at i="<<i<<" now heap is "<<endl;
    maxheapify(a,i,n);
    for(i=0;i<n;i++)
    {cout<<a[i]<<" ";}
  }

}

void maxheapify(int a[] , int i ,int n)
{
  int l,r,large;
  l=left(i);
  r=right(i);
  if(l<n && a[l]>a[i])
  {
    large=l;
  }
  else large=i;
  if(r<n && a[r]>a[large])
{
  large =r;
}
if(large!=i)
{
  int t;
  t=a[i];
  a[i]=a[large];
  a[large]=t;
  maxheapify(a,large,n);
}
}

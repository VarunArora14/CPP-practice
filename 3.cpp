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

// C++ program for building Heap from Array 

#include <iostream> 

using namespace std; 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. N is size of heap 
void heapify(int arr[], int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) { 
		swap(arr[i], arr[largest]); 

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest); 
	} 
} 
int count=0;
// Function to build a Max-Heap from the given array 
void buildHeap(int arr[], int n) 
{ 
	// Index of last non-leaf node 
	int startIdx = (n / 2) - 1; 

	// Perform reverse level order traversal 
	// from last non-leaf node and heapify 
	// each node 
	for (int i = startIdx; i >= 0; i--) { 
    cout<<count++;
		heapify(arr, n, i); 
	} 
} 

// A utility function to print the array 
// representation of Heap 
void printHeap(int arr[], int n) 
{ 
	cout << "Array representation of Heap is:\n"; 

	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 

// Driver Code 
int main() 
{ 
	// Binary Tree Representation 
	// of input array 
	      // 1 
	//		 /	 \ 
  	// 3		 5 
  //	/ \	  / \ 
	// 4	 6 13 10 
//  / \ / \ 
// 9  8 15 17 
	//int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
  int arr[]={16,4,10,14,7,9,3,2,8,1};

	int n = sizeof(arr) / sizeof(arr[0]); 
cout<<"size is "<<n<<" and array is "<<endl;
for(int i=0;i<n;i++)
{
  cout<<arr[i]<<" ";
}
	buildHeap(arr, n); 

	printHeap(arr, n); 
	// Final Heap: 
	// 17 
	//		 /	 \ 
	// 15		 13 
	//	 / \	 / \ 
	// 9	 6 5 10 
	//	 / \ / \ 
	// 4 8 3 1 

	return 0; 
} 

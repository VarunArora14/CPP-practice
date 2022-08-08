#include <iostream>

using namespace std;
void merge(int a[], int, int, int);
void mergesort(int a[], int, int);
int main()
{
    int i, s, a[20];
    cout << "size";
    cin >> s;
    for (i = 0; i < s; i++)
    {
        cin >> a[i];
    }
    mergesort(a, 0, s - 1);

    for (i = 0; i < s; i++)
    {
        cout << a[i] << " ";
    }
}

void mergesort(int a[], int l, int h)
{
    int m;
    if (l < h)
    {
        m = l + (h - 1) / 2; // same as (l+h)/2 but avoid overflow
        mergesort(a, l, m);
        mergesort(a, m + 1, h);
        merge(a, l, m, h);
    }
}

void merge(int a[], int l, int m, int h)
{
    // merges 2 arrays
    // first from l to m
    // second from m+1 to h
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = h - m;

    int L[n1], R[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/*
The merge sort taught before is about merging two SORTED arrays in which are sorted in
increasing or decreasing order and then combining them to form a new array which can be sorted
in increasing or decreasing order.
Here we will have an unordered array in which using recursion we would create small arrays from
the data and using recursion we will sort the small subarrays and then combine/merge them
into an ordered array.
*/
#include<iostream>
#include<stdlib.h>

using namespace std;

    
 // namespace std;

int dealnnoy(int n, int m) 
{ 
    // Base case 
    if (m == 0 || n == 0) 
        return 1; 
  
    // Recursive step. 
    return dealnnoy(m - 1, n) +  
           dealnnoy(m - 1, n - 1) + 
           dealnnoy(m, n - 1); 
} 
  
// Driven Program 
int main() 
{ 
    int n, m;
    cout<<"enter n ";
    cin>>n;
    cout<<"enter m ";
    cin>>m; 
    cout << dealnnoy(n, m) << endl; 
    return 0; 
} 
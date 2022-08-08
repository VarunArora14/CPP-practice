#include<iostream>
using namespace std;
#define m 1000000007
int main()
{
	int x = 5, sum = 0, n = 10;
	sum += x;
	while (n--)
	{
		sum += (sum % m);
		cout << sum << "\n";
	}
}
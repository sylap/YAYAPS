#include <iostream>
using namespace std;

int n;

int main()
{
	cin >> n;
	
	cout << ((n+1)/2)*((n+1)/2) + (n/2)*(n/2) << "\n";
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << ((i+j)%2 == 0 ?'C' :'.');
		cout << "\n";
	}
	
	return 0;
}

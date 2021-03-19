#include<iostream>
using namespace std;
#define MOD 42
int main()
{
	int count = 0;
	int n;
	int arr[42] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		cin >> n;
		arr[n % MOD] =1;
	}

	for (int i = 0; i < 42; i++)
	{
		if (arr[i] != 0) count++;
	}
	cout << count << endl;

	return 0;
}

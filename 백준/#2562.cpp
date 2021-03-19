#include<iostream>
using namespace std;

int main()
{
	int max = 0;
	int idx = 0;
	int arr[9] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		if (arr[i] > max)
		{
			max = arr[i];
			idx = i;
		}
	}
	cout << max << endl;
	cout << idx+1 << endl;

}

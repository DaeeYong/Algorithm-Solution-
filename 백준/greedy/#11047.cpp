#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}
int main()
{
	int K, N;
	int count = 0;

	cin >> N >> K;
	int* arr = new int[N];
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N,compare);

	for (int i = 0; i < N; i++)
	{
		count += K / arr[i]; K %= arr[i];
	}

	cout << count << endl;

	delete []arr;
	return 0;
}
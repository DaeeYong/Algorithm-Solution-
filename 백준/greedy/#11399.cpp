#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	int time = 0;
	int p = 0;
	cin >> N;

	int* arr = new int[N];
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	
	for (int i = 0; i < N; i++)
	{
		time = time + arr[i];
		p += time;
		
	}
	cout << p << endl;
	delete[]arr;
	return 0;
}
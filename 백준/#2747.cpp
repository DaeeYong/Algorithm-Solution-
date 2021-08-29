#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int d[45] = { 0, };

int memo_fibo(int n)
{
	/*
	***********���Ҿ������ �ڵ�***************
	d[0] = 1;
	d[1] = 1;

	for (int i = 2; i < n; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}
	return d[n - 1];
	*******************************************
	*/

	/*
	****************ž�ٿ����� �ڵ�**************
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (d[n] != 0) return d[n];

	d[n] = memo_fibo(n - 1) + memo_fibo(n - 2);
	return d[n];
	***********************************************
	*/
}

int main()
{
	int N;
	int fibo;
	cin >> N;
	
	fibo = memo_fibo(N);
	
	cout << fibo << '\n';

	return 0;
}
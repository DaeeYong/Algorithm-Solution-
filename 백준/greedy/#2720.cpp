#include<iostream>
using namespace std;

int main()
{
	int Q=25, D=10, N=5, P = 1;
	int q=0, d=0, n = 0,p=0;
	int T;
	int change;
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{	
		cin >> change;
		q = change / Q; change %= Q;
		d = change / D; change %= D;
		n = change / N; change %= N;
		p = change / P;

		cout << q << ' ' << d << ' ' << n << ' ' << p << endl;
	}

	return 0;
}
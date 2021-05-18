#include<iostream>
using namespace std;

int main()
{
	int A=300, B=60, C=10;
	int a=0, b=0, c = 0;
	int T;
	cin >> T;
	
	a += T / A; T %= A; 
	b += T / B; T %= B;
	c += T / C; T %= C;
	if (T == 0)
		cout << a << ' ' << b << ' ' << c<<endl;
	else cout << -1 << endl;
	return 0;
}
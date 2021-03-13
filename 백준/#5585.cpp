#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
int main()
{
	int Pay;
	int result=0;
	cin >> Pay;
	
	Pay = 1000 - Pay;

	result += Pay / 500;
	Pay %= 500;
	result += Pay / 100;
	Pay %= 100;
	result += Pay / 50;
	Pay %= 50;
	result += Pay / 10;
	Pay %= 10;
	result += Pay / 5;
	Pay %= 5;
	result += Pay / 1;
	
	cout << result << endl;
	
	return 0;
}
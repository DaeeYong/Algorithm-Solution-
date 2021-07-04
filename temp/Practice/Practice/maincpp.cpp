
#include<iostream>

using namespace std;

int constructNum(int N)
{	
	int countNum = 1;
	int num;
	int temp;
	while (countNum < N)
	{
		num = countNum;
		temp = countNum;
		while (temp != 0)
		{
			num += temp % 10;
			temp /= 10;
		}
		if (num == N) return countNum;
		countNum += 1;
	}
	return 0;
}
int main()
{
	int N;
	cin >> N;

	cout << constructNum(N) << '\n';

	return 0;
}
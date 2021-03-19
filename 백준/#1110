#include<iostream>
using namespace std;

int main()
{
	int num;
	int result;
	int count = 0;
	cin >> num;
	result = num;
	while (1)
	{
		int ten = result / 10;
		int unit = result % 10;
		int sum = (ten + unit) % 10;
		result = (unit * 10) + sum;

		count++;
		if (result == num) break;
	}

	cout << count << endl;
	return 0;
}

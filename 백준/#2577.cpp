#include<iostream>
using namespace std;

int main()
{
	int a, b, c;
	int result;
	int arr[10] = { 0 }; //각 자리수의 변수에 저장

	cin >> a >> b >> c; //숫자 입력
	result = a * b * c;

	while (result != 0)
	{
		arr[result % 10] += 1;
		result /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}

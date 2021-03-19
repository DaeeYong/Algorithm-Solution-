#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int N;
	int sum = 0;
	int count =1;
	char quiz[80];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> quiz;
		for (int j = 0; j < strlen(quiz); j++)
		{
			if (quiz[j] == 'O') sum += count++; //O이면 더하고, count를 1 증가
			else count = 1; //X가 나오면 count를 1로 초기화
		}
		cout << sum << endl;
		sum = 0; //초기화
		count = 1; //초기화
	}

	return 0;
}

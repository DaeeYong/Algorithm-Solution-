#include<stdio.h>

int result(int N);

int main()
{
	int N;
	scanf("%d", &N);
	printf("%d\n", result(N));
	return 0;
}

int result(int N)
{
	int hundred; //백의자리
	int ten; //십의자리
	int one; //일의 자리
	int cnt = 99;
	if (N < 100)
		return N;
	for (int i = 100; i <= N; i++)
	{
		hundred =i/ 100;
		ten = i / 10 % 10;
		one =i%10;
		if ((hundred - ten) == (ten - one)) cnt++;
	}
	return cnt;
}

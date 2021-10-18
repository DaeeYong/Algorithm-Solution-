#define _CRT_SECURE_NO_WARNINGS

//시간복잡도 O(n)
#include<cstdio>

int dice[7];

int reward(int max) {

	for (int i = 1; i <= 6; i++) {
		if (dice[i] == 3) return 10000 + (i * 1000);
		if (dice[i] == 2) return 1000 + (i * 100);
	}

	return max * 100;
}

int main()
{
	int number;
	int max = 0;
	int result;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &number);
		dice[number] += 1;
		
		if (max < number) max = number;
	}
	result = reward(max);

	printf("%d\n", result);

	return 0;
}

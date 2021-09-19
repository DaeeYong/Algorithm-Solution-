#include<cstdio>
#include<cstring>
int cache[5001];

int min(int a, int b)
{
	if (a == -1) return b;
	else if (b == -1) return a;
	else return a < b ? a : b;
}

int solve(int weight)
{
	cache[3] = 1;
	cache[5] = 1;

	int compare;

	for (int i = 6; i <= weight; i++) {
		compare = min(cache[i - 3], cache[i - 5]);
		if (compare == -1) cache[i] = -1;
		else cache[i] = min(cache[i - 3], cache[i - 5]) + 1;
	}
	
	return cache[weight];
}
int main()
{
	memset(cache, -1, sizeof(cache));
	int weight;
	int result;

	scanf("%d", &weight);

	result = solve(weight);
	printf("%d\n", result);

	return 0;
}

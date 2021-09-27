#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>

long long cache[101] = {0,1,1,1,2,2,3,4,5,7,9,0 };

void solve(int n)
{
	for (int i = 11; i <= n; i++) {
		cache[i] = cache[i - 2] + cache[i - 3];
	}

	printf("%lld\n", cache[n]);
}

int main()
{
	int t;
	int n;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		solve(n);
	}

	return 0;
}














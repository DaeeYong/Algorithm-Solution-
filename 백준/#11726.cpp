#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>

int dp[10001] = { 0,1,3 };

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i-1] + 2 * dp[i - 2])%10007;
	}
	printf("%d\n", dp[n]);

	return 0;
} 
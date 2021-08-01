#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
int min(int a, int b) { return a < b ? a : b; }

int cost[1000][3];
int dp[1000][3];


int main(void)
{
	int n;

	scanf("%d", &n);
	
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < 3; k++) {
			scanf("%d", &cost[j][k]);
		}
	}
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];

	for (int j = 1; j < n; j++) {
		dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
		dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + cost[j][1];
		dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + cost[j][2];
	}

	int ans = 100000;

	for (int i = 0; i < 3; i++) {
		if (dp[n - 1][i] < ans) ans = dp[n - 1][i];
	}

	printf("%d\n", ans);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
using namespace std;

int t[16] = { 0, };
int p[16] = { 0,};
int dp[17] = { 0, };

int max(int x, int y)
{
	return x > y ? x : y;
}
int main()
{
	int n;
	int next;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", t + i, p + i);
	}

	for (int i = n; i > 0; --i) {
		next = i + t[i];
		if (next > n + 1) dp[i] = dp[i + 1];
		else {
			dp[i] = max(dp[i+1], p[i] + dp[next]);
		}
	}

	printf("%d ", dp[1]);
	return 0;
}

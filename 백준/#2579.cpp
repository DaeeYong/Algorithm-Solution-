#include<cstdio>
#include<cstdlib>
int dp[301] = { 0, };

int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n;
	//step1 : jump ÇÑ Ä­, step2 : jump µÎ Ä­
	int step1, step2;

	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * (n+1));
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", arr + i);
	}
	
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	
	step1 = arr[3] + arr[2];
	step2 = arr[3] + arr[1];

	dp[3] = Max(step1, step2);


	for (int i = 4; i <= n; i++) {
		step1 = arr[i] + arr[i - 1] + dp[i - 3];
		step2 = arr[i] + dp[i - 2];
		dp[i] = Max(step1, step2);
	}

	printf("%d\n", dp[n]);
	free(arr);
	return 0;
}
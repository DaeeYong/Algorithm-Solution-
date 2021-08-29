#include <iostream>
#include<algorithm>

using namespace std;

int dp[1000001];

int main()
{
	int x;
	cin >> x;
	
	for (int i = 2; i <= x; i++) {
		
		//1을 빼는 경우
		dp[i] = dp[i - 1] + 1;
		//2로 나눠지는 경우
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		//3으로 나눠지는 경우
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}
	for (int i = 0; i < 10; i++)
		cout << dp[i];
	cout << dp[x] << '\n';
	return 0;
}
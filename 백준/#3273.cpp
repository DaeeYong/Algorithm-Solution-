#define __CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>
using namespace std;

int arr[1000001];
int record[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	int input;
	int check;
	int cnt = 0;
	int x;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		arr[i] = input;
		record[input] += 1;
	}
	cin >> x;
	
	/*예외처리 부분(없어도 통과 가능하지만, 찝찝해서 넣음.)
	정상적인 입력에서는  ai의 값은 1보다 크거나 같고, 1_000_000보다 작거나 같은 자연수이므로,
	(0 < x <= 2_000_000) 이어야  한다.
	*/
	if (x > 2000001) {
		cout << cnt << '\n';
		return 0;
	}

	for (int i = 0; i < n; i++) {
		check = x - arr[i];
		if (check < 0) continue;
		if (record[check]) cnt++;
	}
	cout << cnt / 2 << '\n';
	return 0;
}
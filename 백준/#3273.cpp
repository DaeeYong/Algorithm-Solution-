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
	
	/*����ó�� �κ�(��� ��� ����������, �����ؼ� ����.)
	�������� �Է¿�����  ai�� ���� 1���� ũ�ų� ����, 1_000_000���� �۰ų� ���� �ڿ����̹Ƿ�,
	(0 < x <= 2_000_000) �̾��  �Ѵ�.
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
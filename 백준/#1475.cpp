#define __CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>
using namespace std;

int numArr[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	int ans = 0;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		int curNum = s[i] - '0';
		numArr[curNum] += 1;
	}

	for (int i = 0; i< 10; i++) {
		if (i == 6 || i == 9) continue;
		if (ans < numArr[i]) ans = numArr[i];
	}

	int sixNine = (numArr[6] + numArr[9] + 1) / 2;
	if (ans < sixNine) ans = sixNine;

	cout << ans << '\n';

	return 0;
}
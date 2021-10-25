#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;
	int n;
	int input;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == 0) v.pop_back();
		else v.push_back(input);
	}
	for (auto i : v) sum += i;

	cout << sum << '\n';
	return 0;
}

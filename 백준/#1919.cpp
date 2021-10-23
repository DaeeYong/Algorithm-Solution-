#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[26] = {};
	int count = 0;
	string s1;
	string s2;
	
	cin >> s1 >> s2;
	
	for (auto c : s1) arr[c - 'a'] += 1;
	for (auto c : s2) arr[c - 'a'] -= 1;

	for (int i : arr) {
		if (i != 0) count += abs(i);
	}
	cout << count << '\n';

	return 0;
}
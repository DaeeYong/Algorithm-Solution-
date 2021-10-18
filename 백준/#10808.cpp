#include <bits/stdc++.h>
using namespace std;

string arr;
int alphabet[26] = { 0, };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> arr;
	
	for (int i = 0; i < arr.size(); i++) {
		alphabet[arr[i] - 97] += 1;
	}
	
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << ' ';
	}
	
	return 0;
}

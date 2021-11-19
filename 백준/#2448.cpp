#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>
using namespace std;
const int MAX = 1024 * 3;

char board[MAX][MAX * 2];

void paintStar(int x, int y) {
	board[x][y + 2] = '*';
	board[x + 1][y + 1] = '*';
	board[x + 1][y + 3] = '*';

	for (int i = 0; i < 5; i++) {
		board[x + 2][y + i] = '*';
	}
}

void solve(int n, int x, int y) {
	if (n == 3){
		paintStar(x, y);
		return;
	}
	int half = n/2;
	solve(half, x, y + half);
	solve(half, x + half, y);
	solve(half, x + half, y + n);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			board[i][j] = ' ';
		}
		
	}
	
	solve(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
	return 0;
}
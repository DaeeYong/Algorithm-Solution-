#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>
using namespace std;

char board[2200][2200];

void draw(int n, int row, int col) {

	for (int i = col; i < col + n; i++) {
		board[row][i] = '*';
	}

	board[row + 1][col] = '*';
	board[row + 1][col + 2] = '*';

	for (int i = col; i < col + n; i++) {
		board[row + 2][i] = '*';
	}
}

void solve(int n, int row, int col) {
	if (n == 3) {
		draw(n, row, col);
		return;
	}
	int boundary = n / 3;
	solve(boundary,row , col); // 1
	solve(boundary, row, col + boundary); // 2
	solve(boundary, row, col + 2 * boundary); //3
	solve(boundary, row+boundary, col); // 4
	solve(boundary, row+boundary, col + 2* boundary); // 6
	solve(boundary, row + 2* boundary, col); // 7
	solve(boundary, row + 2* boundary, col + boundary); // 8
	solve(boundary, row + 2* boundary, col + 2*boundary); // 9
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c, r;
	cin >> n;
	
	for (int i = 0; i < n; i++) fill(board[i], board[i] + n, ' ');

	solve(n, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}

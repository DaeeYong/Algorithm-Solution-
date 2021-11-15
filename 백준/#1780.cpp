#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>
using namespace std;

int board[2187][2187];
int mins;
int zero;
int one;

void split(int x, int y, int size) {
	int flag = 0;
	int head = board[x][y];
	for (int nx = x; nx < x + size; nx++) {
		for (int ny = y; ny < y + size; ny++) {
			if (board[nx][ny] != head) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	if(flag == 0){
		if (head == -1) mins += 1;
		else if (head == 0)zero += 1;
		else one += 1;
	}
	else {
	int half = size / 3;
	split(x, y, half);
	split(x, y + half, half);
	split(x, y + half + half, half);

	split(x + half, y, half);
	split(x + half, y + half, half);
	split(x + half, y + half + half, half);

	split(x + half + half, y, half);
	split(x + half + half, y + half, half);
	split(x + half + half, y + half + half, half);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	split(0, 0, n);
	cout << mins << '\n';
	cout << zero << '\n';
	cout << one << '\n';
	return 0;
}
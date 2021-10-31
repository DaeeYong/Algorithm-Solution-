#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[1002];
int vis[1002][1002];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int row, col;
	queue<pair<int, int>> FQ;
	queue<pair<int, int>> JQ;
	cin >> row >> col;

	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			cin >> board[x][y];
			if (board[x][y] == 'F') {
				FQ.push({ x,y });
			}
			else if (board[x][y] == 'J') {
				JQ.push({ x,y });
			}
		}
	}

	while (!FQ.empty()) {
		auto cur = FQ.front(); FQ.pop();
		for (int direction = 0; direction < 4; direction++) {
			int nx = cur.X + dx[direction];
			int ny = cur.Y + dy[direction];
			if (board[nx][ny] == '#') continue;
			if (vis[nx][ny] != 0) continue;
			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			FQ.push({ nx,ny });
		}
	}
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			cout << vis[x][y] << ' ';
		}
		
	}
	return 0;
}
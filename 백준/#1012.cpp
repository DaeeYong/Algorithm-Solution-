#define __CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[51][51];
int visited[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
/*
input:
	t
	m n k
	x y

*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, t;
	cin >> t;
	while (t--) {
		queue<pair<int, int>> Q;
		int cnt = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + m, 0);
			fill(visited[i], visited[i] + m, 0);
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != 1 || visited[i][j] == 1) continue;

				cnt++;
				visited[i][j] = 1;
				Q.push({ i,j });

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] != 1 || visited[nx][ny] != 0) continue;
						visited[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
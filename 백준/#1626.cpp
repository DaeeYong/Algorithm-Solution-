#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502];
int vis[502][502];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int sum = 0;
	int count = 0;
	queue<pair<int, int>> Q;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (board[x][y] == 0 || vis[x][y] == 1) continue;
			else {
				int tmp = 1;
				vis[x][y] = 1;
				Q.push({ x,y });

				while (!Q.empty()) {

					pair<int, int> cur = Q.front(); Q.pop();
					for (int direction = 0; direction < 4; direction++) {
						int nx = cur.X + dx[direction];
						int ny = cur.Y + dy[direction];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						tmp += 1;
						Q.push({ nx,ny });
					}
				}
				if (sum < tmp) {
					sum = tmp;
				}
				count += 1;
			}
		}
	}
	
	cout << count << '\n';
	cout << sum << '\n';

	return 0;
}

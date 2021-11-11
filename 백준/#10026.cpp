#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[102];
int vist[102][102];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int three;
	int two;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	//적록색약이 아닌 경우
	int flag = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (vist[x][y] != 0) continue;
			else {
				flag++;
				queue<pair<int, int>> Q;
				vist[x][y] = flag;
				Q.push({ x,y });
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int direction = 0; direction < 4; direction++) {
						int nx = cur.X + dx[direction];
						int ny = cur.Y + dy[direction];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (board[x][y] != board[nx][ny] || vist[nx][ny] != 0) continue;
						vist[nx][ny] = flag;
						Q.push({ nx,ny });
					}
				}
			}
		}
	}

	three = flag;
	flag = 0;
	for (int i = 0; i < n; i++) fill(vist[i], vist[i] + n, 0);
	//적록 색약인 경우
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (vist[x][y] != 0) continue;
			else {
				flag++;
				queue<pair<int, int>> Q;
				vist[x][y] = flag;
				Q.push({ x,y });
				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();
					for (int direction = 0; direction < 4; direction++) {
						int nx = cur.X + dx[direction];
						int ny = cur.Y + dy[direction];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						char colorNow = board[x][y];
						char colorNext = board[nx][ny];
						if ( vist[nx][ny] != 0 || (colorNow == 'R' && colorNext =='B') ||
							(colorNow == 'G' && colorNext == 'B') ||
							(colorNow == 'B' && (colorNext == 'R' || colorNext == 'G'))) continue;
						vist[nx][ny] = flag;
						Q.push({ nx,ny });
					}
				}
			}
		}
	}
	two = flag;

	cout << three << ' ' << two << '\n';
	
	return 0;
}
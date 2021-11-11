#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int dist1[1002][1002]; //불
int dist2[1002][1002]; //상근
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int w, h, t;
	cin >> t;

	for (int testCase = 0; testCase < t; testCase++) {
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			cin >> board[i];
		}
		for (int i = 0; i < h; i++) {
			fill(dist1[i], dist1[i] + w, -1);
			fill(dist2[i], dist2[i] + w, -1);
		}

		queue<pair<int, int>> Q1; //불
		queue<pair<int, int>> Q2; //상근
		bool escape = false;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '*') {
					Q1.push({ i,j }); 
					dist1[i][j] = 0;
				}
				if (board[i][j] == '@') {
					Q2.push({ i,j });
					dist2[i][j] = 0;
				}
			}

		}
		//불에 대한 BFS
		while (!Q1.empty()) {
			auto cur = Q1.front(); Q1.pop();
			for (int direction = 0; direction < 4; direction++) {
				int nx = cur.X + dx[direction];
				int ny = cur.Y + dy[direction];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (board[nx][ny] == '#' || dist1[nx][ny] != -1) continue;
				dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
				Q1.push({ nx,ny });
			}
		}
		//상근이에 대한 BFS	
		while (!Q2.empty()  && !escape) {
			auto cur = Q2.front(); Q2.pop();
			for (int direction = 0; direction < 4; direction++) {
				int nx = cur.X + dx[direction];
				int ny = cur.Y + dy[direction];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					cout << dist2[cur.X][cur.Y] + 1 << '\n';
					escape = true;
					break;
				}
				if (board[nx][ny] == '#' || dist2[nx][ny] != -1 ) continue;
				if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
				dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
				Q2.push({ nx,ny });
			}
		}
		if(!escape) cout << "IMPOSSIBLE" << '\n';
		
	}
	return 0;
}

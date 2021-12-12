#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, m;
int board[8][8];
pair<int, int> pos[6][9];
int cnt[6];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//�ʱ� �Է� �Լ�
void input(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				pos[1][cnt[1]++] = make_pair(i, j);
			}
			else if (board[i][j] == 2) {
				pos[2][cnt[2]++] = make_pair(i, j);
			}
			else if (board[i][j] == 3) {
				pos[3][cnt[3]++] = make_pair(i, j);
			}
			else if (board[i][j] == 4) {
				pos[4][cnt[4]++] = make_pair(i, j);
			}
			else if (board[i][j] == 5) {
				pos[5][cnt[5]++] = make_pair(i, j);
			}
		}
	}
}
//dir �������� ������ ĥ��. 0,1,2,3(�ð����)
void fill(int x, int y, int dir) { //��,��,�Ʒ�,���� : 0,1,2,3
	int nx, ny;
	if (dir == 0) {
		nx = x + dx[dir];
		ny = y + dy[dir];
		while (nx > 0 || board[nx][ny] != -1 || board[nx][ny] != 6) {
			board[nx][ny] = -1;
			nx += dx[dir];
			ny += dy[dir];
		}
	}
	else if (dir == 1) {
		nx = x + dx[dir];
		ny = y + dy[dir];
		while (ny < m || board[nx][ny] != -1 || board[nx][ny] != 6) {
			board[nx][ny] = -1;
			nx += dx[dir];
			ny += dy[dir];
		}
	}
	else if (dir == 2) {
		nx = x + dx[dir];
		ny = y + dy[dir];
		while (nx < n || board[nx][ny] != -1 || board[nx][ny] != 6) {
			board[nx][ny] = -1;
			nx += dx[dir];
			ny += dy[dir];
		}
	}
	else if (dir == 3) {
		nx = x + dx[dir];
		ny = y + dy[dir];
		while (nx > 0 || board[nx][ny] != -1 || board[nx][ny] != 6) {
			board[nx][ny] = -1;
			nx += dx[dir];
			ny += dy[dir];
		}
	}
}
//90�� ȸ��
void rotate(int x, int y, int dir) {
	
}
//����� �� ������ Ȯ��
int blankCheck() { //�� ĭ Ȯ��
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) cnt += 1;
		}
	}
	return cnt;
}
//CCTV������ ���� �������� Ȯ��
int observing() {
	pair<int, int> cur;

	for (int posIdx = 5; posIdx > 0; posIdx--) {
		for (int num = 0; num < cnt[posIdx]; num++) {
			cur = pos[posIdx][num];
			int x = cur.X;
			int y = cur.Y;
			if (posIdx == 5) {
				fill(x, y, 0);
				fill(x, y, 1);
				fill(x, y, 2);
				fill(x, y, 3);
			}
			else if (posIdx == 4) {

			}
			else if (posIdx == 3) {

			}
			else if (posIdx == 2) {

			}
			else if (posIdx == 1) {

			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	input(n, m);
	
	
	return 0;
}
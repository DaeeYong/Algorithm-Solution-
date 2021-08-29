#include<iostream>
#include<utility>

using namespace std;

string board[50];
string white[8] =
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string black[8] =
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int BCnt(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i + x][j + y] != black[i][j])
				cnt += 1;
		}
	}
	return cnt;
}
int WCnt(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i + x][j + y] != white[i][j])
				cnt += 1;
		}
	}
	return cnt;
}

int main()
{
	int min_val = 100000;
	int tmp;
	pair<int, int> p;
	cin >> p.first >> p.second;

	for (int i = 0; i < p.first; i++)
		cin >> board[i];

	for (int i = 0; i + 8 <= p.first; i++) {
		for (int j = 0; j + 8 <= p.second; j++) {
			tmp = min(BCnt(i,j),WCnt(i,j));
			if (tmp < min_val) min_val = tmp;
		}
	}
	cout << min_val;

	return 0;
}
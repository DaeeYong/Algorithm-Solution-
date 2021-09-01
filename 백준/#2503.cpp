#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

typedef struct _game {
	int number;
	int strike;
	int ball;
}Game;

vector<Game> v;
bool Can_Number[1000];

void Init()
{
	memset(Can_Number, true, sizeof(Can_Number));
	for (int i = 123; i < 999; i++) {
		string tmp = to_string(i);
		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
			Can_Number[i] = false;
		if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0)
			Can_Number[i] = false;
	}
}

int solve()
{ 
	int result = 0;
	int number;
	int strike;
	int ball;
	string origin;
	int tmp_strike = 0;
	int tmp_ball = 0;

	Init();

	for (int i = 0; i < v.size(); i++) {
		number = v[i].number;
		strike = v[i].strike;
		ball = v[i].ball;

		origin = to_string(number);

		for (int j = 123; j < 999; j++) {

			if (Can_Number[j] == true) {
				tmp_strike = 0;
				tmp_ball = 0;
				string tmp = to_string(j);
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						if (a == b && origin[a] == tmp[b]) tmp_strike += 1;
						if (a != b && origin[a] == tmp[b]) tmp_ball += 1;
					}
				}
				if (strike != tmp_strike || ball != tmp_ball) Can_Number[j] = false;
			}
		}
	}
	for (int i = 123; i < 999; i++)
		if (Can_Number[i] == true) result += 1;
	return result;
}
int main()
{
	int n;
	Game g;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &(g.number), &(g.strike), &(g.ball));
		v.push_back(g);
	}
	printf("%d\n", solve());
}
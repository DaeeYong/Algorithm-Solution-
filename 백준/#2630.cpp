#include<cstdio>

int paper[128][128];
int numOfBlue = 0;
int numOfWhite = 0;

void paparCutter(int y, int x, int size)
{
	int flag = 0;
	int head = paper[y][x];

	for (int dy = 0; dy < size; dy++) {
		for (int dx = 0; dx < size; dx++) {
			if (paper[y + dy][x + dx] != head) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}

	if (flag != 1) {
		if (head == 1) numOfBlue += 1;
		else numOfWhite += 1;
		return;
	}

	else {
		int half = size / 2;
		paparCutter(y, x, half);
		paparCutter(y, x + half, half);
		paparCutter(y + half, x, half);
		paparCutter(y + half, x + half, half);

		return;
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	paparCutter(0, 0, t);

	printf("%d\n%d\n", numOfWhite, numOfBlue);

	return 0;
}

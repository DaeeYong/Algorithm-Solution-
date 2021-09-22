#include<cstdio>

char data[64][64];

void quadTree(int y, int x, int size)
{
	char head = data[y][x];
	bool pass = true;
	int dx, dy;

	for (dy = 0; dy < size; dy++) {
		for (dx = 0; dx < size; dx++) {
			if (head != data[y + dy][x + dx]) {
				pass = false;
				break;
			}
		}
		if (pass == false) break;
	}

	if (pass) {
		printf("%c", head);
	}
	else {
		int half = size / 2;

		printf("(");
		quadTree(y, x, half);
		quadTree(y, x + half, half);
		quadTree(y + half, x, half);
		quadTree(y + half, x + half, half);
		printf(")");
	}
}
int main()	
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", data + i);
	}

	quadTree(0, 0, n);

	return 0;
}

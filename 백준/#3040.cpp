#include<cstdio>
#include<vector>

#define TARGET 100

using namespace std;

vector<int> v(9);

int main()
{	
	int tmp;
	int sum = 0;
	int checkIdx1, checkIdx2;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &v[i]);
		sum += v[i];
	}

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			tmp = v[i] + v[j];
			
			if ((sum - tmp) == TARGET) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					printf("%d\n", v[k]);
				}
			}
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>

int cache[1000];
int arr[1000];
int n;

int lis() {
	int max = 1;
	cache[0] = 1;
	for (int i = 1; i < n; i++) {
		cache[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && (cache[i] < cache[j] + 1))
				cache[i] = cache[j] + 1;
		}
		if(max < cache[i])
			max = cache[i];
	}
	return max;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	printf("%d", lis());

	return 0;
}
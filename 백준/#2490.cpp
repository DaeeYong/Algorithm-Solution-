#include<cstdio>

int arr[2];

int main()
{
	int number;

	for (int k = 0; k < 3; k++) {
		arr[0] = 0;
		arr[1] = 0;
		for (int i = 0; i < 4; i++) {
			scanf("%d", &number);
			arr[number] += 1;
		}

		switch (arr[0])
		{
		case 1:
			printf("A\n");
			break;
		case 2:
			printf("B\n");
			break;
		case 3:
			printf("C\n");
			break;
		case 4:
			printf("D\n");
			break;
		case 0:
			printf("E\n");
		}
	}
	return 0;
}

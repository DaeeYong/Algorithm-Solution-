#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int testCase;
	double average=0;
	int count = 0; //평균을 넘는 학생 수
	cin >> testCase;
	

	for (int i = 0; i < testCase; i++)
	{
		int N;
		cin >> N;
		int* arr = new int[N]; //학생 수에 따른 배열 크기 동적할당
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j];
			average += arr[j];
		}
		average /= (double)N; //학생들 평균 점수

		/***평균 넘는 학생 확인***/
		for (int j = 0; j < N; j++)
		{
			if (arr[j] > average) count += 1;
		}
		//cout << "count : " << count << "everage : " << average << endl;
		
		printf("%.3f%%\n", (double)count / N*100);
		
		average = 0;
		count = 0;
		delete[] arr;

	}
	return 0;
}

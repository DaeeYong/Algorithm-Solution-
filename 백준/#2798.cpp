#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#define MAX 98
int Card[MAX]; //카드 저장할 배열 선언
using namespace std;
int Black_Jack(int N, int M); //블랙잭 계산 함수
int main()
{
	int N, M;
	int result; //정답 저장 변수

	cin >> N >> M; 

	//카드 입력
	for (int i = 0; i < N; i++)
	{
		cin >> Card[i];
	}

	result = Black_Jack(N, M); //결과계산
	
	cout << result << endl; 
	return 0;
}
int Black_Jack(int N, int M)
{
	int sumOfMax = 0; //최대합 저장 변수
	int tmpSum = 0; //임시 합 저장 변수

	//완전검색 알고리즘 시작, 카드3장에 대한 모든 경우의 수 계산(순열)
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j != i)
			{
				for (int k = 0; k < N; k++)
				{
					if (k != i && k != j)
					{
						tmpSum = Card[i] + Card[j] + Card[k];
						if (tmpSum > sumOfMax && tmpSum <= M)
							sumOfMax = tmpSum;
					}
				}
			}
		}
	}

	//완전검색 알고리즘 끝
	return sumOfMax;
}
#include<iostream>
using namespace std;

int main()
{
	int N; //시험 본 과목의 개수
	int max=0; //최댓값
	double average = 0; //평균
	cin >> N;

	double* val = new double[N];
	for (int i = 0; i < N; i++)
	{
		cin >> val[i];
		if (val[i] > max)
		{
			max = val[i];
		}
	}

	/**점수 조작 시작***/
	for (int i = 0; i < N; i++)
	{
		val[i] = (double)val[i] / max * 100;
		average += val[i];
	}
	/****조작된 점수로 평균 구하기***/
	cout << average/N << endl;
	delete[] val; //할당 해제

	return 0;
}

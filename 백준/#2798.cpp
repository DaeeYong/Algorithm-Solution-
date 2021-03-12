#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#define MAX 98
int Card[MAX]; //ī�� ������ �迭 ����
using namespace std;
int Black_Jack(int N, int M); //���� ��� �Լ�
int main()
{
	int N, M;
	int result; //���� ���� ����

	cin >> N >> M; 

	//ī�� �Է�
	for (int i = 0; i < N; i++)
	{
		cin >> Card[i];
	}

	result = Black_Jack(N, M); //������
	
	cout << result << endl; 
	return 0;
}
int Black_Jack(int N, int M)
{
	int sumOfMax = 0; //�ִ��� ���� ����
	int tmpSum = 0; //�ӽ� �� ���� ����

	//�����˻� �˰��� ����, ī��3�忡 ���� ��� ����� �� ���(����)
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

	//�����˻� �˰��� ��
	return sumOfMax;
}
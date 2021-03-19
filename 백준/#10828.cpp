#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<cstring>
#include<iostream>

using namespace std;

//���Ḯ��Ʈ�� stack ����

typedef struct _node
{
	int data;
	struct _node* next=NULL;
}Node;

typedef struct _stack
{
	Node* head = NULL;
	int numOfData = 0; //stack�� �����ϴ� data�� �� ǥ��

}Stack;

//push �Լ�
void push(Stack* pstack, int data)
{
	if (pstack->head == NULL) //stack�� ����ִ� ���
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->next = NULL;
		pstack->head = newNode;
		pstack->head->data = data;
		(pstack->numOfData)++;
	}
	else //stack�� ������� �ʴ� ��쿡 head�κп� ���ο� ��� �߰�
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->next = NULL;
		newNode->data = data;
		newNode->next = pstack->head;
		pstack->head = newNode;
		(pstack->numOfData)++;
	}
}

//pop����
int pop(Stack* pstack)
{
	Node* removeNode;
	int removeData;

	//stack��  ����ִ� ��� -1�� ��ȯ
	if (pstack->head == NULL) return -1;

	removeNode = pstack->head; //������ ��� 
	removeData = pstack->head->data; //������ ����� ������
	pstack->head = pstack->head->next; //������ ����� �� ���� ��带 head�� ����Ŵ.

	free(removeNode); //�Ҵ�����
	(pstack->numOfData)--; //data�� ���� �ϳ� ����
	return removeData; 
}

//stack�� size ��ȯ
int size(Stack* pstack)
{
	return pstack->numOfData;
}


//stack�� ����ִ��� ���� Ȯ��
int empty(Stack* pstack)
{
	if (pstack->head == NULL) return 1; //����ִٸ� 1 ��ȯ
	else return 0; //������� �ʴٸ� 0 ��ȯ
}

//stack�� ���� ���� �ִ� data ��ȯ
int top(Stack* pstack)
{	
	if (pstack->head == NULL) return -1; //��ȯ�� data�� ���ٸ� -1 ����
	else return pstack->head->data;
}

int main()
{	
	Stack stack;
	stack.head = NULL; //stack�� head�� NULL�� �ʱ�ȭ
	int N;
	int data;
	char str[6];
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;

		//������ �Է� ��쿡 ���� �˸��� �Լ��� ����
		if (!strcmp(str, "push"))
		{	
			cin >> data;
			push(&stack, data);
		}
		else if (!strcmp(str, "pop"))
		{
			cout << pop(&stack)<<endl;
		}
		else if (!strcmp(str, "size"))
		{
			cout << size(&stack) << endl;
		}
		else if (!strcmp(str, "empty"))
		{
			cout << empty(&stack) << endl;
		}
		else if (!strcmp(str, "top"))
		{
			cout << top(&stack) << endl;
		}
		else //������� �Է��� ���� �� ����ó��
		{
			printf("commend is not exist, error! \n");
			exit(-1);
		}
	}
	//Ȥ�ó� �� �޸� ������ ���� ���ؼ� Ȯ���ϰ� �Ҵ� ����
	while (!(stack.head == NULL))
	{
		Node* remove = NULL;
		remove = stack.head;
		stack.head = stack.head->next;
		free(remove);
	}
	return 0;
}


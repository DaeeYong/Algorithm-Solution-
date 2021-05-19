#include<iostream>
using namespace std;

typedef struct _bucket
{
	int start;
	int end=1;
} Bucket;
int main()
{
	int N, M, J;
	Bucket bucket;
	int distance = 0; 
	int position = 0;
	int length = 0;
	cin >> N >> M;
	bucket.start = M;
	cin >> J;

	for (int i = 0; i < J; i++)
	{	
		cin >> position;
		if (bucket.start < position)
		{
			distance = (position - bucket.start);
			bucket.start += distance;
			bucket.end += distance;
			length += distance;
		}
		else if (bucket.end > position)
		{
			distance = (bucket.end - position);
			bucket.end -= distance;
			bucket.start -= distance;
			length += distance;
		}
	}
	cout << length << endl;
	return 0;
}
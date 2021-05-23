#include<iostream>
using namespace std;

int main()
{
	char arr[51];
	int seat;
	int count = 1;
	int couple = 0;

	cin>>seat;
	cin>>arr;

	for(int i=0; arr[i] != NULL; i++)
	{
		if(arr[i] == 'S') count++;
		else if(arr[i] == 'L')
		{
			couple +=1;
			if(couple %2 == 0) count++;
		}
	}
	if(seat > count) cout<<count<<endl;
	else cout<<seat<<endl;

	return 0;

}

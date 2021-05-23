#include<iostream>
#include<cstring>
#include<stdio.h>

using namespace std;

#define MAX_LEN 1001

int main(void)
{
	char arr[MAX_LEN];
	
	char final[5] = "UCPC";	
	int check=0;

	fgets(arr,1001,stdin);
	
	for(int i=0; arr[i] != NULL; i++)
	{
		if(arr[i] == final[check])
		{
			check++;
		}
		if(check == 4) break;
	}

	if(check == 4) cout<<"I love UCPC"<<endl;
	else cout<<"I hate UCPC"<<endl;
	
	return 0;
}



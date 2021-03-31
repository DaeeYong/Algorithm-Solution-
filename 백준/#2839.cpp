#include<iostream>
using namespace std;


int Solution(int PsugarWeight)
{
	int numOf_5_Bag = PsugarWeight / 5;
	int tmp = 0;

	if (PsugarWeight < 3) PsugarWeight = -1;

	while (numOf_5_Bag != -1)
	{
		tmp = PsugarWeight - (5 * numOf_5_Bag);
		if (tmp % 3 == 0)
		{
			return numOf_5_Bag + (tmp / 3);
		}
		numOf_5_Bag--;
	}
	return -1;
}
int main()
{
	int sugarWeight;
	int numberOfBag=0;
	cin >> sugarWeight;
	
	cout<<Solution(sugarWeight)<<endl;

	
	return 0;
}
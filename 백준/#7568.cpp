#include<iostream>
#include<vector>

using namespace std;
typedef pair<int, int> p;

void compare(vector<p> v,int grade[])
{
	int count;
	for (int i = 0; i < v.size(); i++){
		count = 1;

		for (int j = 0; j < v.size(); j++){
		
			if (j == i) continue;
			if ((v[i].first < v[j].first) &&
				(v[i].second < v[j].second)) {
				count += 1;
			}
		}
		grade[i] = count;
	}
}

int main()
{
	vector<p> arr;
	int N;
	int w, h;
	cin >> N;
	int* grade = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> w >> h;
		arr.push_back(make_pair(w, h));
	}
	compare(arr, grade);
	
	for (int i = 0; i < N; i++)
	{
		cout << grade[i] << ' ';
	}
	cout << '\n';

	delete []grade;

	return 0;
}
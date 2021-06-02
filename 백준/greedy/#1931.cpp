#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, int> p;
vector<p> arr;

bool compare(p a, p b);
int main()
{
	int N;
	cin >> N;
	
	int s, e;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> e;
		arr.push_back(make_pair(s, e));
	}
	sort(arr.begin(), arr.end(), compare);

	int latest_end_time = 0;
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		if (latest_end_time <= arr[i].first)
		{
			count += 1;
			latest_end_time = arr[i].second;
			//cout << "select: [" << arr[i].first << ", " << arr[i].second <<"]"<< endl;
		
		}
	}

	cout << count << endl;
	return 0;
}

bool compare(p a, p b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}
}
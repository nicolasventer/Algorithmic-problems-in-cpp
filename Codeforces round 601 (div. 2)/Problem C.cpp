#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

using PP = pair<int, int>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int t_size = n-2;

	vector<bool> b_used(n+1, false);
	vector<vector<int>> t_list_list(n+1, vector<int>());

	for (int i = 0; i < t_size; ++i)
	{
		int t[3];
		for (int j = 0; j < 3; ++j)
		{
			cin >> t[j];
		}
		t_list_list[t[0]].push_back(t[1]);
		t_list_list[t[0]].push_back(t[2]);
		t_list_list[t[1]].push_back(t[0]);
		t_list_list[t[1]].push_back(t[2]);
		t_list_list[t[2]].push_back(t[0]);
		t_list_list[t[2]].push_back(t[1]);
	}
	int first;
	for (first = 0; first <= n; ++first)
	{
		if (t_list_list[first].size() == 2)
			break;
	}
	int second;
	for (int i = 0; i < 2; ++i)
	{
		second = t_list_list[first][i];

		if (t_list_list[second].size() == 4)
			break;
	}
	cout << first << " " << second;
	b_used[first] = b_used[second] = true;
	int third;
	for (int i = 0; i < t_size; ++i)
	{
		for (auto t : t_list_list[first])
		{
			if (!b_used[t])
			{
				third = t;
				break;
			}
		}
		cout << " " << third;
		first = second;
		second = third;
		b_used[third] = true;
	}
	return 0;
}

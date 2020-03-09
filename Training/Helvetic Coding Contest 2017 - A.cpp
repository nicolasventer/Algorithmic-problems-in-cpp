#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unsigned int n,k;
	cin >> n >> k;

	set<int> s;
	int a[n];

	vector<vector<int>> s_list;
	s_list.push_back(vector<int>(n, 0));
	for (unsigned int i = 0; i < n; ++i)
	{
		cin >> a[i];
		s_list.push_back(s_list.back());
		for (unsigned int j = 0; j < i; ++j)
		{
			++s_list[j][a[i]];
		}
	}

/*
	for (unsigned int i = 0; i < n; ++i)
	{
		cout << i << endl;
		for (auto e : s_list[i])
			cout << e << " ";
		cout << endl;
	}
*/

	set<int> current_s;
	int res = 0;
	unsigned int i = 0;
	while(i < n)
	{
		if (current_s.find(a[i]) == current_s.end())
		{
			current_s.insert(a[i]);
			++res;
			if (current_s.size() == k)
			{
				++i;
				break;
			}
		}
		++i;
	}
	while(i < n)
	{
		/*
		cout << endl << i << " " << a[i] << endl;
		for (auto p : current_s)
			cout << p << " ";
		cout << endl;
		*/
		if (current_s.find(a[i]) == current_s.end())
		{
			auto to_remove = current_s.begin();
			for (auto it = current_s.begin(); it != current_s.end(); ++it)
			{
				if (s_list[i][*to_remove] > s_list[i][*it])
					to_remove = it;
			}
			//cout << *to_remove << " " << s_list[i][*to_remove] << endl;
			current_s.erase(to_remove);
			current_s.insert(a[i]);
			++res;
		}
		
		++i;
	}

	cout << res << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		map<string, int> _00_map;
		map<string, int> _01_map;
		map<string, int> _10_map;
		map<string, int> _11_map;
		for (int i = 1; i <= n; ++i)
		{
			string k;
			cin >> k;
			if (k.front() == '0')
			{
				if (k.back() == '0')
					_00_map[k] = i;
				else
					_01_map[k] = i;
			}
			else
			{
				if (k.back() == '0')
					_10_map[k] = i;
				else
					_11_map[k] = i;
			}
		}
		if (_01_map.empty() && _10_map.empty())
		{
			// no transition 0 to 1 -> check if one of them is empty => ok if it is
			cout << (_00_map.empty() || _11_map.empty() ? "0\n" : "-1") << endl;
			continue;
		}
		int diff = _01_map.size() - _10_map.size();
		if (abs(diff) <= 1)
		{
			cout << 0 << endl << endl;
			continue;
		}
		map<string, int> to_reverse_map;
		map<string, int> other_map;
		if (diff > 0)
		{
			to_reverse_map = _01_map;
			other_map = _10_map;
		}
		else
		{
			to_reverse_map = _10_map;
			other_map = _01_map;
			diff = -diff; // positive diff
		}
		vector<int> res;
		for (auto to_reverse : to_reverse_map)
		{
			string s = to_reverse.first;
			reverse(s.begin(), s.end());
			if (other_map.find(s) == other_map.end())
			{
				res.push_back(to_reverse.second);
			}
		}
		if ((int)res.size() >= diff - 1)
		{
			int mid_diff = diff/2;
			cout << mid_diff << endl;
			for (int i = 0; i < mid_diff; ++i)
			{
				cout << res[i] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}

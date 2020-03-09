#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		string s;
		string t;
		cin >> s;
		cin >> t;
		vector<pair<int, int>> swap_list;

		bool b_impossible = false;

		for (int j = 0; j < n; j++)
		{
			bool b_swap_pushed;
			do
			{
				b_swap_pushed = false;
				if (s[j] == t[j])
					continue;
				auto s_f = s.find(s[j], j+1);
				if (s_f == string::npos)
				{
					auto t_f = t.find(s[j], j+1);
					if (t_f == string::npos)
					{
						b_impossible = true;
						break;
					}
					swap(s[t_f], t[t_f]);
					swap_list.push_back(make_pair(t_f, t_f));
					swap(s[t_f], t[j]);
					swap_list.push_back(make_pair(t_f, j));
					b_swap_pushed = true;
				}
				else
				{
					swap(s[s_f], t[j]);
					swap_list.push_back(make_pair(s_f, j));
					b_swap_pushed = true;
				}

			} while (b_swap_pushed);

		}

		if (b_impossible)
			cout << "No" << endl;
		else
		{
			cout << "Yes\n" << swap_list.size() << endl;
			for (auto swap : swap_list)
				cout << (swap.first+1) << " " << (swap.second+1) << endl;
		}
	}

	return 0;
}

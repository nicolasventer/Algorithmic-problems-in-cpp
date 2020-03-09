#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	set<int> is_inside;
	set<int> was_inside;

	bool res = true;
	vector<int> day_list;
	for (int i = 0; i < n; i++)
	{
		int index;
		cin >> index;
		if (!res)
			continue;
		if (index > 0)
		{
			auto was_pos = was_inside.find(index);
			if (was_pos != was_inside.end()) // was inside and not new day
			{
				res = false;
				continue;
			}
			is_inside.insert(index);
			was_inside.insert(index);
		}
		else
		{
			auto is_pos = is_inside.find(-index);
			if (is_pos == is_inside.end()) // is not inside
			{
				res = false;
				continue;
			}
			is_inside.erase(is_pos);
			if (is_inside.size() == 0)
			{
				day_list.push_back(i);
				was_inside.clear();
			}
		}
	}
	if (!was_inside.empty())
		res = false;
	if (res)
	{
		cout << day_list.size() << endl;
		int last_day = 0;
		for (auto day : day_list)
		{
			cout << (day+1 - last_day) << " ";
			last_day = day+1;
		}
	}
	else
	{
		cout << -1;
	}

	return 0;
}

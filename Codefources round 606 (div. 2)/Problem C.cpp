#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	string twone = string("twone");
	string one = string("one");
	string two = string("two");
	
	while (t--)
	{
		string s;
		cin >> s;
		vector<int> res;
		size_t pos = 0;
		while (true)
		{
			pos = s.find(twone, pos);
			if (pos == string::npos)
				break;
			res.push_back(pos+3);
			s[pos+2] = '-';
		}
		pos = 0;
		while (true)
		{
			pos = s.find(one, pos);
			if (pos == string::npos)
				break;
			res.push_back(pos+2);
			s[pos+1] = '-';
		}
		pos = 0;
		while (true)
		{
			pos = s.find(two, pos);
			if (pos == string::npos)
				break;
			res.push_back(pos+2);
			s[pos+1] = '-';
		}

		cout << res.size() << endl;
		for (auto r : res)
			cout << r << " ";
		cout << endl;
	}
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool contains(const vector<int>& v, int e)
{
	for (auto u : v)
	{
		if (u == e)
			return true;
	}
	return false;
}

bool contains(const set<int>& v, int e)
{
	for (auto u : v)
	{
		if (u == e)
			return true;
	}
	return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r[26];
	for (int i = 0; i < 26; ++i)
		r[i] = -1;
	long n;
	cin >> n;
	for (long i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		vector<int> v;
		for (auto t : s)
		{
			int u = t - 'a';
			if (r[u] != -1)
			{
				v.push_back(r[u]);
			}
		}
		if (v.empty())
		{
			for (auto t : s)
			{
				int u = t - 'a';
				r[u] = i;
			}
		}
		else
		{
			int ref = v.back();
			for (int j = 0; j < 26; ++j)
			{
				if (contains(v, r[j]))
				{
					r[j] = ref;
				}
			}
			for (auto t : s)
			{
				int u = t - 'a';
				r[u] = ref;
			}
		}
	}
	set<int> res(begin(r), end(r));
	cout << (res.size() - (contains(res, -1) ? 1 : 0)) << endl;
	return 0;
}

// solution accepted : 113min
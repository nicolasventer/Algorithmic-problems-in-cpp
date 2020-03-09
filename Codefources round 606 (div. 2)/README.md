## [A. Happy Birthday, Polycarp!](http://codeforces.com/contest/1277/problem/A)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>
#include <math.h>

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
		if (n < 10)
		{
			cout << n << endl;
			continue;
		}
		int k = log10(n);
		int min = 0;
		int p10 = 1;
		for (int i = 0; i <= k; ++i)
		{
			min += p10;
			p10 *= 10;
		}
		cout << n/min + k * 9 << endl;
	}
	return 0;
}
```
</details>

## [B. Make Them Odd](http://codeforces.com/contest/1277/problem/B)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;


long rec_div2(set<int>& el_set, int e)
{
	if (el_set.find(e) != el_set.end())
		return 0;
	el_set.insert(e);
	if (e%2 == 1)
		return 0;
	return 1 + rec_div2(el_set, e/2);
}

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
		long res = 0;
		set<int> el_set;
		while (n--)
		{
			int a;
			cin >> a;
			res += rec_div2(el_set, a);
		}
		cout << res << endl;
	}
	return 0;
}
```
</details>

## [C. As Simple as One and Two](http://codeforces.com/contest/1277/problem/C)

<details>
<summary>Show solution</summary>

```C++
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
```
</details>

## [D. Let's Play the Words?](http://codeforces.com/contest/1277/problem/D)

<details>
<summary>Show solution</summary>

```C++
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
```
</details>


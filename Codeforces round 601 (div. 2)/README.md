## [A. Changing Volume](http://codeforces.com/contest/1255/problem/A)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int a,b;
		cin >> a >> b;
		int diff = a > b ? a - b : b - a;
		if (diff%5 == 4)
			diff += 2;
		int q5 = diff/5;
		int q2 = (diff%5)/2;
		int q1 = (diff+q5)%2;
		cout << (q5 + q2 + q1) << endl;;
	}
	return 0;
}
```
</details>

## [B. Fridge Lockers](http://codeforces.com/contest/1255/problem/B)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
	{
		long n, m;
		cin >> n >> m;
		long long res = 0;
		for (int i = 0; i < n; ++i)
		{
			long e;
			cin >> e;
			res += e;
		}
		if (m != n || n <= 2)
		{
			cout << -1 << endl;
			continue;
		}
		cout << 2 * res << endl;
		for (int i = 1; i < n; ++i)
		{
			cout << i << " " << (i+1) << endl;
		}
		cout << n << " " << 1 << endl;
	}	
	return 0;
}
```
</details>

## [C. League of Leesins](http://codeforces.com/contest/1255/problem/C)

<details>
<summary>Show solution</summary>

```C++
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
```
</details>

## [D. Feeding Chicken](http://codeforces.com/contest/1255/problem/D)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>

using namespace std;

char char_array[] =
{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		long r, c, k;
		cin >> r >> c >> k;
		char t[r][c];
		long rice_count = 0;
		for (long i = 0; i < r; ++i)
		{
			for (long j = 0; j < c; ++j)
			{
				cin >> t[i][j];
				if (t[i][j] == 'R')
					rice_count++;
			}
		}
		long rice_list[k];
		long q = rice_count/k;
		for (long i = 0; i < k; ++i)
		{
			rice_list[i] = q;
		}
		long rest = rice_count%k;
		for (long i = 0; i < rest; ++i)
		{
			++rice_list[i];
		}
		long index = 0;
		int mid_r = r/2;
		long double_i = 0;
		for (long i = 0; i < mid_r; ++i)
		{
			
			for (long j = 0; j < c; ++j)
			{
				cout << char_array[index];
				if (t[double_i][j] == 'R' && index + 1 < k)
				{
					if (!--rice_list[index])
						index++;
				}
			}
			++double_i;
			cout << endl;
			char temp[c];
			for (long j = c-1; j >= 0; --j)
			{
				temp[j] = char_array[index];
				if (t[double_i][j] == 'R' && index + 1 < k)
				{
					if (!--rice_list[index])
						index++;
				}
			}
			for (long j = 0; j < c; ++j)
				cout << temp[j];
			++double_i;
			cout << endl;
		}
		if (r%2)
		{
			for (long j = 0; j < c; ++j)
			{
				cout << char_array[index];
				if (t[double_i][j] == 'R' && index + 1 < k)
				{
					if (!--rice_list[index])
						index++;
				}
			}
			cout << endl;
		}
	}
	return 0;
}
```
</details>


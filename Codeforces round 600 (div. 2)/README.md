## [A. Single Push](http://codeforces.com/contest/1253/problem/A)

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
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int a[n];

		for (int j = 0; j < n; j++)
			cin >> a[j];
		bool op_done = false;
		bool break_done = false;
		bool res = true;
		int offset = 0;
		for (int j = 0; j < n; j++)
		{
			int b;
			cin >> b;
			if (!res)
				continue;
			if (op_done)
			{
				if (!break_done)
				{
					if (b + offset != a[j])
						break_done = true;
				}
				if (break_done)
				{
					if (b != a[j])
					{
						res = false;
						continue;
					}
				}
			}
			else
			{
				if (b != a[j])
				{
					if (b < a[j])
					{
						res = false;
						continue;
					}
					op_done = true;
					offset = a[j] - b;
				}
			}
		}
		cout << (res ? "YES" : "NO") << endl;
	}

	return 0;
}
```
</details>

## [B. Silly Mistake](http://codeforces.com/contest/1253/problem/B)

<details>
<summary>Show solution</summary>

```C++
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
```
</details>

## [C. Sweets Eating](http://codeforces.com/contest/1253/problem/C)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int m;
	cin >> m;
	int a[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(&a[0], &a[n]);

	long long cumul_a[n];
	cumul_a[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		cumul_a[i] = cumul_a[i-1] + a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cout << cumul_a[i] << " ";
	}
	for (int i = m; i < n; i++)
	{
		cumul_a[i] += cumul_a[i-m];
		cout << cumul_a[i] << " ";
	}

	return 0;
}
```
</details>

## [D. Harmonious Graph](http://codeforces.com/contest/1253/problem/D)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Kruskal
{
public:
	Kruskal(int size)
	{
		parent = new int[size];
		for (int i = 0; i < size; ++i)
		{
			parent[i] = i;
		}
	}
	~Kruskal()
	{
		delete[] parent;
	}
	int find(int i)
	{
		if (parent[i] == i)
			return i;
		return parent[i] = (find(parent[i]));
	}

	void union1(int i, int j)
	{
		int a = find(i);
		int b = find(j);
		parent[a] = b;
	}

private:
	int* parent = 0;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	Kruskal k(n+1);
	set<int> e_set;
	int max = 0;
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin >> a >> b;
		k.union1(a, b);
		e_set.insert(a);
		e_set.insert(b);
		if (max < a)
			max = a;
		if (max < b)
			max = b;
	}
	int res = 0;
	bool done[n+1];
	for (int i = 0; i < n+1	; ++i)
	{
		done[i] = false;
	}
	vector<int> r;
	for (int i = 1; i <= max; ++i)
	{
		int t = k.find(i);
		if (done[t])
		{
			while (k.find(r.back()) != k.find(t))
			{
				k.union1(r.back(), t);
				done[r.back()] = false;
				r.pop_back();
				++res;
			}
		}
		else
		{
			done[t] = true;
			r.push_back(t);
		}
	}
	cout << res << endl;

	return 0;
}
```
</details>


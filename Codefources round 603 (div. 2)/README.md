## [A. Sweet Problem](http://codeforces.com/contest/1263/problem/A)

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

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int rgb_array[3];
		cin >> rgb_array[0] >> rgb_array[1] >> rgb_array[2];
		sort(&rgb_array[0], &rgb_array[3]);
		int sum = rgb_array[0] + rgb_array[1];
		if (rgb_array[2] > sum)
			rgb_array[2] = sum;
		int res = (rgb_array[0] + rgb_array[1] + rgb_array[2]) / 2;
		cout << res << endl;
	}
	return 0;
}
```
</details>

## [B. PIN Codes](http://codeforces.com/contest/1263/problem/B)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>
#include <vector>

using namespace std;

void compute_new_pin(bool* p, int* all_pin, int new_j)
{
	int base = 1;
	for (int k = 0; k < 4; ++k)
	{
		int before = all_pin[new_j] / (10 * base);
		int after = all_pin[new_j] % base;
		for (int l = 0; l < 10; ++l)
		{
			int res = before * 10 * base + l * base + after;
			if (!p[res])
			{
				p[res] = true;
				all_pin[new_j] = res;
				return;
			}
		}
		base *= 10;
	}
	throw "not found";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		bool p[10000] = {false};
		int all_pin[n];
		vector<int> v;
		for (int j = 0; j < n; ++j)
		{
			cin >> all_pin[j];
			if (p[all_pin[j]])
			{
				v.push_back(j);
			}
			else
				p[all_pin[j]] = true;
		}
		for (auto new_j : v)
		{
			compute_new_pin(p, all_pin, new_j);
		}
		cout << v.size() << endl;
		for (auto pin : all_pin)
		{
			if (pin < 10)
				cout << "000";
			else if (pin < 100)
				cout << "00";
			else if (pin < 1000)
				cout << "0";
			cout << pin << endl;
		}
	}
	return 0;
}
```
</details>

## [C. Everyone is a Winner!](http://codeforces.com/contest/1263/problem/C)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		long n;
		cin >> n;
		vector<long> v(1,0);
		for (long j = n; j > 0; j--)
		{
			long res = n / j;
			v.push_back(res);
			j = (n / (res + 1) + 1);
		}
		cout << v.size() << endl;
		for (auto u : v)
		{
			cout << u << " ";
		}
		cout << endl;
	}
	return 0;
}
```
</details>

## [D. Secret Passwords](http://codeforces.com/contest/1263/problem/D)

<details>
<summary>Show solution</summary>

```C++
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
```
</details>

<details>
<summary>Show solution v2</summary>

```C++
#include <iostream>
#include <string>
#include <set>

using namespace std;

class Kruskal
{
public:
	class Set_Range
	{
		class Iterator
		{
		public:
			Iterator(int current, int* parent, bool b_last_reached) : current(current), parent(parent),
				b_last_reached(b_last_reached) {};
			inline void operator++() { b_last_reached = current == parent[current]; current = parent[current]; }
			inline bool operator!=(const Iterator& other) const
				{  return current != other.current || b_last_reached != other.b_last_reached; }
			inline int operator*() { return current; }
		private:
			int current = 0;
			int* parent = 0;
			bool b_last_reached = false;
		};
	public:
		Set_Range(int start_i, int end_i, int* parent) : start_i(start_i), end_i(end_i), parent(parent) {}
		inline Iterator begin() { return Iterator(start_i, parent, false); }
		inline Iterator end() { return Iterator(end_i, parent, true); }
	private:
		int start_i = 0;
		int end_i = 0;
		int* parent = 0;
	};

public:
	Kruskal(int size)
	{
		root = new int[size];
		parent = new int[size];
		start = new int[size];
		for (int i = 0; i < size; ++i)
		{
			root[i] = parent[i] = start[i] = i;
		}
	}
	~Kruskal()
	{
		delete[] root;
		delete[] parent;
		delete[] start;
	}
	int find(int i)
	{
		if (root[i] == i)
			return i;
		return root[i] = find(root[i]);
	}

	void union1(int i, int j)
	{
		int a = find(i);
		int b = find(j);
		u_root_set.insert(b);
		if (a == b)
			return;
		root[a] = b;
		parent[a] = start[b];
		start[b] = start[a];
		u_root_set.erase(a);
	}

	inline Set_Range get_set_range(int i)
		{ return Set_Range(start[root[i]], root[i], parent); }

	inline const std::set<int>& get_u_root_set() { return u_root_set; }

private:
	int* root = 0;
	int* parent = 0;
	int* start = 0;

	std::set<int> u_root_set;

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Kruskal k(26);
	long n;
	cin >> n;
	for (long i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		int ref = s[0] - 'a';
		for (auto t : s)
		{
			int u = t - 'a';
			k.union1(ref, u);
		}
	}
	cout << k.get_u_root_set().size() << endl;
	return 0;
}
```
</details>
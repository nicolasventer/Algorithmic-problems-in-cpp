## [A. Equation](http://codeforces.com/contest/1269/problem/A)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long a;
	cin >> a;
	cout << 16 * a << " " << 15 * a << endl;

	return 0;
}
```
</details>

## [B. Modulo Equality](http://codeforces.com/contest/1269/problem/B)

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
	long long m;
	cin >> n >> m;

	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int b[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}

	sort(a, a+n);
	sort(b, b+n);

	auto find = [&] (int k)
	{
		int ref = (b[k] - a[0] + m)%m;
		for (int i = 0; i < n; ++i)
		{
			if ((b[(i+k)%n] - a[i] + m)%m != ref)
				return false;
		}
		return true;
	};

	int res = m;
	for (int i = 0; i < n; ++i)
	{
		if (find(i))
		{
			res = min(res, static_cast<int>((b[i] - a[0] + m)%m));
		}
	}
	cout << res << endl;

	return 0;
}
```
</details>

## [C. Long Beautiful Integer](http://codeforces.com/contest/1269/problem/C)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int a[n];
	for (int i = 0; i < n; ++i)
	{
		char c;
		cin >> c;
		a[i] = c - '0';
	}

	int p;
	for (p = 0; p + k < n; ++p)
	{
		if (a[p] < a[p+k])
			break;
	}

	if (p + k < n) // a[p] < a[p+k]
	{
		int j = p+k-1;
		while (j >= 0 && (a[j] == 9 || (j-k >= 0 && a[j-k] == a[j])))
		{
			a[j] = 0;
			--j;
		}
		if (j == -1)
		{
			cout << n+1 << endl;
			for (int l = 0; l < n+1; ++l)
			{
				cout << (l%k == 0 ? 1 : 0);
			}
			cout << endl;
			return 0;
		}
		++a[j];
	}

	for (int i = 0; i < n - k; ++i)
	{
		a[i+k] = a[i];
	}
	
	cout << n << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << a[i];
	}
	cout << endl;
	return 0;
}
```
</details>

## [D. Domino for Young](http://codeforces.com/contest/1269/problem/D)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long res=0, x=0, y=0;
	for (int i = 0; i < n; ++i)
	{
		long long a;
		cin >> a;
		res += a >> 1;
		if (a & 1) // a is odd
		{
			if (i & 1) // i is odd
				++x;
			else
				++y;
		}
	}
	cout << res + min(x, y) << endl;
	return 0;
}
```
</details>



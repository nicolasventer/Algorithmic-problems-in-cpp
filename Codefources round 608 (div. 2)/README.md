## [A. Suits](http://codeforces.com/contest/1271/problem/A)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a,b,c,d,e,f;

	cin >> a >> b >> c >> d >> e >> f;

	if (e > f)
	{
		int type1 = min(a,d);
		d -= type1;
		cout << type1 * e + min(min(b,c), d) * f << endl;
	}
	else
	{
		int type2 = min(min(b,c), d);
		d -= type2;
		cout << min(a,d) * e + type2 * f << endl;
	}

	return 0;
}
```
</details>

## [B. Blocks](http://codeforces.com/contest/1271/problem/B)

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

	int n;
	cin >> n;
	int start_n = n;
	int is_even = n%2 == 1;
	char c;
	cin >> c;
	bool isBlack = c == 'B';
	bool b_reversed = false;
	vector<int> res;
	for (int i = 2; i < n; ++i)
	{
		cin >> c;
		bool c_isBlack = c == 'B';

		if (c_isBlack == isBlack)
		{
			if (b_reversed)
				res.push_back(i);
			else
				b_reversed = false;
		}
		else
		{
			if (b_reversed)
				b_reversed = false;
			else
			{
				b_reversed = true;
				res.push_back(i);
			}
		}
	}
	cin >> c;
	bool c_isBlack = c == 'B';
	if ((c_isBlack != b_reversed) != isBlack)
	{
		if (is_even)
		{
			cout << res.size() + start_n/2 << endl;
			for (auto t : res)
			{
				cout << t << " ";
			}
			for (int i = 1; i < start_n; i+=2)
			{
				cout << i << " ";
			}
			cout << endl;
			return 0;
		}
		cout << -1 << endl;
		return 0;
	}
	cout << res.size() << endl;
	for (auto t : res)
	{
		cout << t << " ";
	}
	cout << endl;
	return 0;
}
```
</details>

## [C. Shawarma Tent](http://codeforces.com/contest/1271/problem/C)

<details>
<summary>Show solution</summary>

```C++
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int pupil_count;
	cin >> pupil_count;
	int school_x, school_y;
	cin >> school_x >> school_y;

	int gt_x = 0;
	int gt_y = 0;
	int lt_x = 0;
	int lt_y = 0;
	while (pupil_count--)
	{
		int p_x, p_y;
		cin >> p_x >> p_y;
		if (p_x > school_x)
			gt_x++;
		else if (p_x < school_x)
			lt_x++;
		if (p_y > school_y)
			gt_y++;
		else if (p_y < school_y)
			lt_y++;
	}

	int m = max(max(gt_x, gt_y), max(lt_x, lt_y));
	cout << m << endl;
	if (m == gt_x)
	{
		cout << school_x+1 << " " << school_y << endl;
		return 0;
	}
	if (m == gt_y)
	{
		cout << school_x << " " << school_y+1 << endl;
		return 0;
	}
	if (m == lt_x)
	{
		cout << school_x-1 << " " << school_y << endl;
		return 0;
	}
	if (m == lt_y)
	{
		cout << school_x << " " << school_y-1 << endl;
		return 0;
	}

	return 0;
}
```
</details>


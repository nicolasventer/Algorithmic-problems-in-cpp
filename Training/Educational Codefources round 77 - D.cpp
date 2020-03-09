#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m,n,k,t;
		// m : allies count, n : level length, 
		// k : trap count, t : time to succeed
	cin >> m >> n >> k >> t;

	int a[m];
	for (int i = 0; i < m; ++i)
	{
		cin >> a[i];
	}

	int l[k], r[k], d[k];
	// l : trap location, r : trap disable location, d : trap difficulty
 	int sl[k];

	for (int i = 0; i < k; ++i)
	{
		cin >> l[i] >> r[i] >> d[i];
		sl[i] = i;
	}

	sort(a, a+m);
	sort(sl, sl+k, [&](int a, int b)
		{ return l[a] < l[b]; });

	auto check = [&](int N)
	{
		vector<int> v;
		for (int i = 0; i < k; ++i)
		{
			if (d[sl[i]] > N)
				v.push_back(sl[i]);
		}
		int time_spent = 0;
		int unlocked_to = 0;
		for (auto u : v)
		{
			if (r[u] <= unlocked_to)
			{
				continue;
			}
			if (unlocked_to < l[u])
			{
				unlocked_to = l[u] - 1;
			}
			time_spent += r[u] - unlocked_to;
			unlocked_to = r[u];
		}
		return (n + 1) + (time_spent << 1) <= t; // mult by 2
	};

	int low = 0;
	int high = m-1;

	if (!check(a[m-1]))
	{
		cout << 0 << endl;
		return 0;
	}
	while(low < high)
	{
		int mid = (low + high) >> 1; // div by 2
		if (check(a[mid]))
			high = mid;
		else
			low = mid + 1;
	}
	cout << m - low << endl;
	return 0;
}
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

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

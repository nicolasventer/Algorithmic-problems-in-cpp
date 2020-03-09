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

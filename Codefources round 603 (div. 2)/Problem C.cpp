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

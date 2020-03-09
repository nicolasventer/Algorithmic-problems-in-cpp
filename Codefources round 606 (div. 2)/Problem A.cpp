#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n < 10)
		{
			cout << n << endl;
			continue;
		}
		int k = log10(n);
		int min = 0;
		int p10 = 1;
		for (int i = 0; i <= k; ++i)
		{
			min += p10;
			p10 *= 10;
		}
		cout << n/min + k * 9 << endl;
	}
	return 0;
}

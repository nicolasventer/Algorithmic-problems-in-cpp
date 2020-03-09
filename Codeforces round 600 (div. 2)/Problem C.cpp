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

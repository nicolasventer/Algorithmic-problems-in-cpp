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

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int a[n];

		for (int j = 0; j < n; j++)
			cin >> a[j];
		bool op_done = false;
		bool break_done = false;
		bool res = true;
		int offset = 0;
		for (int j = 0; j < n; j++)
		{
			int b;
			cin >> b;
			if (!res)
				continue;
			if (op_done)
			{
				if (!break_done)
				{
					if (b + offset != a[j])
						break_done = true;
				}
				if (break_done)
				{
					if (b != a[j])
					{
						res = false;
						continue;
					}
				}
			}
			else
			{
				if (b != a[j])
				{
					if (b < a[j])
					{
						res = false;
						continue;
					}
					op_done = true;
					offset = a[j] - b;
				}
			}
		}
		cout << (res ? "YES" : "NO") << endl;
	}

	return 0;
}

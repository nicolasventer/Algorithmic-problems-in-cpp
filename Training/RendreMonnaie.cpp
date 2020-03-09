#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int S[] ={1, 2, 5, 10, 20, 50};
	int size = sizeof(S) / sizeof(S[0]);

	int a_rendre[] = { 12, 23 , 48, 35, 96 };

	for (auto p : a_rendre)
	{
		cout << p << endl;
		int dp[p+1];
		int m[p+1];
		dp[0] = 0;
		for (int i = 1; i < p+1; ++i)
			dp[i] = 100;
		for (int i = 0; i < p+1; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (S[j] > i)
					continue;
				int new_dp = dp[i-S[j]]+1;
				if (new_dp < dp[i])
				{
					dp[i] = new_dp;
					m[i] = S[j];
				}
			}
		}
		cout << dp[p] << endl;
		int i = p;
		while (m[i] > 0 && i > 0)
		{
			cout << m[i] << " ";
			i -= m[i];
		}
		cout << endl;
	}

	return 0;
}

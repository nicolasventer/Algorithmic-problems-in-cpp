#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// maximiser le poids en minimisant le volume

	int poids[] = { 12, 23 , 48, 35, 96 };
	int volume[] = { 45, 13, 12 ,15, 65 };

	int size = sizeof(poids)/sizeof(poids[0]);

	int maxP = 0;
	for (int i = 0; i < size; ++i)
	{
		maxP += poids[i];
	}
	int dp[maxP+1];
	int m[maxP+1];

	for (int i = 0; i < maxP+1; ++i)
	{
		dp[i] = -1;
	}

	dp[0] = 0;

	for (int i = 0; i < maxP+1; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (poids[j] > i || dp[i - poids[j]] == -1)
				continue;
			int new_dp = dp[i - poids[j]] + volume[j];
			if (dp[i] == -1 || new_dp < dp[i])
			{
				dp[i] = new_dp;
				m[i] = j;
			}
		}
	}

	int a_peser[] = { 143, 122, 45, 86, 134, 245 };
	for (auto p : a_peser)
	{
		cout << p;
		p = min(p, maxP);
		while (dp[p] == -1)
			--p;
		cout << " -> " << p << endl;
		cout << dp[p] << endl;
		while (dp[p] > 0 && p > 0)
		{
			cout << "(" << poids[m[p]] << ", " << volume[m[p]] << ")" << " ";
			p -= poids[m[p]];
		}
		cout << endl;
	}

	return 0;
}

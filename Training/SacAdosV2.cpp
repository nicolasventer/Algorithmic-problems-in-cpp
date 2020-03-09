#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// maximiser la valeur en minimisant le poids et le volume
	// maximiser la valeur en minimisant le volume et
	// maximiser la valeur en minimisant le poids et
	// prendre le minimum des valeures maximales respectant les conditions

	int value[] = { 2, 3, 6, 5, 8 };

	int poids[] = { 12, 23 , 48, 35, 96 };
	int volume[] = { 45, 13, 12 ,15, 65 };

	int size = sizeof(poids)/sizeof(poids[0]);

	int maxP = 0;
	int maxV = 0;
	for (int i = 0; i < size; ++i)
	{
		maxP += poids[i];
		maxV += volume[i];
	}
	int dpP[maxP+1];
	int mP[maxP+1];

	for (int i = 0; i < maxP+1; ++i)
	{
		dpP[i] = -1;
	}

	dpP[0] = 0;

	for (int i = 0; i < maxP+1; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (poids[j] > i || dpP[i - poids[j]] == -1)
				continue;
			int new_dp = dpP[i - poids[j]] + value[j];
			if (dpP[i] == -1 || new_dp < dpP[i])
			{
				dpP[i] = new_dp;
				mP[i] = j;
			}
		}
	}

	int dpV[maxP+1];
	int mV[maxV+1];

	for (int i = 0; i < maxV+1; ++i)
	{
		dpV[i] = -1;
	}

	dpV[0] = 0;

	for (int i = 0; i < maxV+1; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (volume[j] > i || dpV[i - volume[j]] == -1)
				continue;
			int new_dp = dpV[i - volume[j]] + value[j];
			if (dpV[i] == -1 || new_dp < dpV[i])
			{
				dpV[i] = new_dp;
				mV[i] = j;
			}
		}
	}

	int a_mesurer[] = { 35, 48, 86, 130, 46 };
	int a_peser[] = { 143, 122, 45, 86, 134, 245 };
	int count = sizeof(a_mesurer)/sizeof(a_mesurer[0]);
	for (int i = 0; i < count; ++i)
	{
		int p = a_peser[i];
		int v = a_mesurer[i];
		cout << "[" << p << ", " << v << "]" << endl;
		int p1 = min(p, maxP);
		while (dpP[p1] == -1)
			--p1;
		int p2 = min(v, maxV);
		while (dpV[p2] == -1)
			--p2;
		cout << dpP[p1] << " " << dpV[p2] << endl;
		if (dpP[p1] < dpV[p2]) // prendre la valeur la plus contraingante
		{
			p = p1;
			cout << " -> (poids) " << p << endl;
			cout << dpP[p] << endl;
			while (dpP[p] > 0 && p > 0)
			{
				cout << "(" << poids[mP[p]] << ", " << volume[mP[p]] << ")" << " ";
				p -= poids[mP[p]];
			}
			cout << endl;
		}
		else
		{
			p = p2;
			cout << " -> (volume) " << p << " " << endl;
			cout << dpV[p] << endl;
			while (dpV[p] > 0 && p > 0)
			{
				cout << "(" << poids[mV[p]] << ", " << volume[mV[p]] << ")" << " ";
				p -= volume[mV[p]];
			}
			cout << endl;
		}
	}

	return 0;
}

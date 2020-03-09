#include <iostream>
#include <vector>

using namespace std;

void compute_new_pin(bool* p, int* all_pin, int new_j)
{
	int base = 1;
	for (int k = 0; k < 4; ++k)
	{
		int before = all_pin[new_j] / (10 * base);
		int after = all_pin[new_j] % base;
		for (int l = 0; l < 10; ++l)
		{
			int res = before * 10 * base + l * base + after;
			if (!p[res])
			{
				p[res] = true;
				all_pin[new_j] = res;
				return;
			}
		}
		base *= 10;
	}
	throw "not found";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		bool p[10000] = {false};
		int all_pin[n];
		vector<int> v;
		for (int j = 0; j < n; ++j)
		{
			cin >> all_pin[j];
			if (p[all_pin[j]])
			{
				v.push_back(j);
			}
			else
				p[all_pin[j]] = true;
		}
		for (auto new_j : v)
		{
			compute_new_pin(p, all_pin, new_j);
		}
		cout << v.size() << endl;
		for (auto pin : all_pin)
		{
			if (pin < 10)
				cout << "000";
			else if (pin < 100)
				cout << "00";
			else if (pin < 1000)
				cout << "0";
			cout << pin << endl;
		}
	}
	return 0;
}

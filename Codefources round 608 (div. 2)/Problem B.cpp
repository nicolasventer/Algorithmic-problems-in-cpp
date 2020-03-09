#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int start_n = n;
	int is_even = n%2 == 1;
	char c;
	cin >> c;
	bool isBlack = c == 'B';
	bool b_reversed = false;
	vector<int> res;
	for (int i = 2; i < n; ++i)
	{
		cin >> c;
		bool c_isBlack = c == 'B';

		if (c_isBlack == isBlack)
		{
			if (b_reversed)
				res.push_back(i);
			else
				b_reversed = false;
		}
		else
		{
			if (b_reversed)
				b_reversed = false;
			else
			{
				b_reversed = true;
				res.push_back(i);
			}
		}
	}
	cin >> c;
	bool c_isBlack = c == 'B';
	if ((c_isBlack != b_reversed) != isBlack)
	{
		if (is_even)
		{
			cout << res.size() + start_n/2 << endl;
			for (auto t : res)
			{
				cout << t << " ";
			}
			for (int i = 1; i < start_n; i+=2)
			{
				cout << i << " ";
			}
			cout << endl;
			return 0;
		}
		cout << -1 << endl;
		return 0;
	}
	cout << res.size() << endl;
	for (auto t : res)
	{
		cout << t << " ";
	}
	cout << endl;
	return 0;
}

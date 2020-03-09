#include <iostream>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;


long rec_div2(set<int>& el_set, int e)
{
	if (el_set.find(e) != el_set.end())
		return 0;
	el_set.insert(e);
	if (e%2 == 1)
		return 0;
	return 1 + rec_div2(el_set, e/2);
}

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
		long res = 0;
		set<int> el_set;
		while (n--)
		{
			int a;
			cin >> a;
			res += rec_div2(el_set, a);
		}
		cout << res << endl;
	}
	return 0;
}

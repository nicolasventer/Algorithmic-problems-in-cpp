#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int a,b;
		cin >> a >> b;
		int diff = a > b ? a - b : b - a;
		if (diff%5 == 4)
			diff += 2;
		int q5 = diff/5;
		int q2 = (diff%5)/2;
		int q1 = (diff+q5)%2;
		cout << (q5 + q2 + q1) << endl;;
	}
	return 0;
}

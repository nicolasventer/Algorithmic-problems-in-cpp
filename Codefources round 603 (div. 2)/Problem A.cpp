#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int rgb_array[3];
		cin >> rgb_array[0] >> rgb_array[1] >> rgb_array[2];
		sort(&rgb_array[0], &rgb_array[3]);
		int sum = rgb_array[0] + rgb_array[1];
		if (rgb_array[2] > sum)
			rgb_array[2] = sum;
		int res = (rgb_array[0] + rgb_array[1] + rgb_array[2]) / 2;
		cout << res << endl;
	}
	return 0;
}

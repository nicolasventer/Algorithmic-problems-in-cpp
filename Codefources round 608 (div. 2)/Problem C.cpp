#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int pupil_count;
	cin >> pupil_count;
	int school_x, school_y;
	cin >> school_x >> school_y;

	int gt_x = 0;
	int gt_y = 0;
	int lt_x = 0;
	int lt_y = 0;
	while (pupil_count--)
	{
		int p_x, p_y;
		cin >> p_x >> p_y;
		if (p_x > school_x)
			gt_x++;
		else if (p_x < school_x)
			lt_x++;
		if (p_y > school_y)
			gt_y++;
		else if (p_y < school_y)
			lt_y++;
	}

	int m = max(max(gt_x, gt_y), max(lt_x, lt_y));
	cout << m << endl;
	if (m == gt_x)
	{
		cout << school_x+1 << " " << school_y << endl;
		return 0;
	}
	if (m == gt_y)
	{
		cout << school_x << " " << school_y+1 << endl;
		return 0;
	}
	if (m == lt_x)
	{
		cout << school_x-1 << " " << school_y << endl;
		return 0;
	}
	if (m == lt_y)
	{
		cout << school_x << " " << school_y-1 << endl;
		return 0;
	}

	return 0;
}

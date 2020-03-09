#include <iostream>

using namespace std;

char char_array[] =
{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		long r, c, k;
		cin >> r >> c >> k;
		char t[r][c];
		long rice_count = 0;
		for (long i = 0; i < r; ++i)
		{
			for (long j = 0; j < c; ++j)
			{
				cin >> t[i][j];
				if (t[i][j] == 'R')
					rice_count++;
			}
		}
		long rice_list[k];
		long q = rice_count/k;
		for (long i = 0; i < k; ++i)
		{
			rice_list[i] = q;
		}
		long rest = rice_count%k;
		for (long i = 0; i < rest; ++i)
		{
			++rice_list[i];
		}
		long index = 0;
		int mid_r = r/2;
		long double_i = 0;
		for (long i = 0; i < mid_r; ++i)
		{
			
			for (long j = 0; j < c; ++j)
			{
				cout << char_array[index];
				if (t[double_i][j] == 'R' && index + 1 < k)
				{
					if (!--rice_list[index])
						index++;
				}
			}
			++double_i;
			cout << endl;
			char temp[c];
			for (long j = c-1; j >= 0; --j)
			{
				temp[j] = char_array[index];
				if (t[double_i][j] == 'R' && index + 1 < k)
				{
					if (!--rice_list[index])
						index++;
				}
			}
			for (long j = 0; j < c; ++j)
				cout << temp[j];
			++double_i;
			cout << endl;
		}
		if (r%2)
		{
			for (long j = 0; j < c; ++j)
			{
				cout << char_array[index];
				if (t[double_i][j] == 'R' && index + 1 < k)
				{
					if (!--rice_list[index])
						index++;
				}
			}
			cout << endl;
		}
	}
	return 0;
}

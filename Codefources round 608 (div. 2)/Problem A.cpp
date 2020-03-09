#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a,b,c,d,e,f;

	cin >> a >> b >> c >> d >> e >> f;

	if (e > f)
	{
		int type1 = min(a,d);
		d -= type1;
		cout << type1 * e + min(min(b,c), d) * f << endl;
	}
	else
	{
		int type2 = min(min(b,c), d);
		d -= type2;
		cout << min(a,d) * e + type2 * f << endl;
	}

	return 0;
}

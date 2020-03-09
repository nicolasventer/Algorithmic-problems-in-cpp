#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Kruskal
{
public:
	Kruskal(int size)
	{
		parent = new int[size];
		for (int i = 0; i < size; ++i)
		{
			parent[i] = i;
		}
	}
	~Kruskal()
	{
		delete[] parent;
	}
	int find(int i)
	{
		if (parent[i] == i)
			return i;
		return parent[i] = (find(parent[i]));
	}

	void union1(int i, int j)
	{
		int a = find(i);
		int b = find(j);
		parent[a] = b;
	}

private:
	int* parent = 0;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	Kruskal k(n+1);
	set<int> e_set;
	int max = 0;
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin >> a >> b;
		k.union1(a, b);
		e_set.insert(a);
		e_set.insert(b);
		if (max < a)
			max = a;
		if (max < b)
			max = b;
	}
	int res = 0;
	bool done[n+1];
	for (int i = 0; i < n+1	; ++i)
	{
		done[i] = false;
	}
	vector<int> r;
	for (int i = 1; i <= max; ++i)
	{
		int t = k.find(i);
		if (done[t])
		{
			while (k.find(r.back()) != k.find(t))
			{
				k.union1(r.back(), t);
				done[r.back()] = false;
				r.pop_back();
				++res;
			}
		}
		else
		{
			done[t] = true;
			r.push_back(t);
		}
	}
	cout << res << endl;

	return 0;
}
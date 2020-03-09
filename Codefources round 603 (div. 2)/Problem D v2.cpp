#include <iostream>
#include <string>
#include <set>

using namespace std;

class Kruskal
{
public:
	class Set_Range
	{
		class Iterator
		{
		public:
			Iterator(int current, int* parent, bool b_last_reached) : current(current), parent(parent),
				b_last_reached(b_last_reached) {};
			inline void operator++() { b_last_reached = current == parent[current]; current = parent[current]; }
			inline bool operator!=(const Iterator& other) const
				{  return current != other.current || b_last_reached != other.b_last_reached; }
			inline int operator*() { return current; }
		private:
			int current = 0;
			int* parent = 0;
			bool b_last_reached = false;
		};
	public:
		Set_Range(int start_i, int end_i, int* parent) : start_i(start_i), end_i(end_i), parent(parent) {}
		inline Iterator begin() { return Iterator(start_i, parent, false); }
		inline Iterator end() { return Iterator(end_i, parent, true); }
	private:
		int start_i = 0;
		int end_i = 0;
		int* parent = 0;
	};

public:
	Kruskal(int size)
	{
		root = new int[size];
		parent = new int[size];
		start = new int[size];
		for (int i = 0; i < size; ++i)
		{
			root[i] = parent[i] = start[i] = i;
		}
	}
	~Kruskal()
	{
		delete[] root;
		delete[] parent;
		delete[] start;
	}
	int find(int i)
	{
		if (root[i] == i)
			return i;
		return root[i] = find(root[i]);
	}

	void union1(int i, int j)
	{
		int a = find(i);
		int b = find(j);
		u_root_set.insert(b);
		if (a == b)
			return;
		root[a] = b;
		parent[a] = start[b];
		start[b] = start[a];
		u_root_set.erase(a);
	}

	inline Set_Range get_set_range(int i)
		{ return Set_Range(start[root[i]], root[i], parent); }

	inline const std::set<int>& get_u_root_set() { return u_root_set; }

private:
	int* root = 0;
	int* parent = 0;
	int* start = 0;

	std::set<int> u_root_set;

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Kruskal k(26);
	long n;
	cin >> n;
	for (long i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		int ref = s[0] - 'a';
		for (auto t : s)
		{
			int u = t - 'a';
			k.union1(ref, u);
		}
	}
	cout << k.get_u_root_set().size() << endl;
	return 0;
}

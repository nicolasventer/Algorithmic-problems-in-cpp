#include <set>

class Kruskal
{
public:
	class Set_Range
	{
		class Iterator
		{
		public:
			Iterator(size_t current, size_t* parent, bool b_last_reached) : current(current), parent(parent),
				b_last_reached(b_last_reached) {};
			inline void operator++() { b_last_reached = current == parent[current]; current = parent[current]; }
			inline bool operator!=(const Iterator& other) const
				{  return current != other.current || b_last_reached != other.b_last_reached; }
			inline size_t operator*() { return current; }
		private:
			size_t current = 0;
			size_t* parent = 0;
			bool b_last_reached = false;
		};
	public:
		Set_Range(size_t start_i, size_t end_i, size_t* parent) : start_i(start_i), end_i(end_i), parent(parent) {}
		inline Iterator begin() { return Iterator(start_i, parent, false); }
		inline Iterator end() { return Iterator(end_i, parent, true); }
	private:
		size_t start_i = 0;
		size_t end_i = 0;
		size_t* parent = 0;
	};

public:
	Kruskal(size_t size)
	{
		root = new size_t[size];
		parent = new size_t[size];
		start = new size_t[size];
		
		for (size_t i = 0; i < size; ++i)
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
	size_t find(size_t i)
	{
		if (root[i] == i)
			return i;
		return root[i] = find(root[i]);
	}

	void union1(size_t i, size_t j)
	{
		size_t a = find(i);
		size_t b = find(j);
		u_root_set.insert(b);
		if (a == b)
			return;
		root[a] = b;
		parent[a] = start[b];
		start[b] = start[a];
		u_root_set.erase(a);
	}

	Set_Range get_set_range(size_t i)
	{ 
		size_t a = find(i);
		return Set_Range(start[a], a, parent);
	}

	inline const std::set<size_t>& get_u_root_set() { return u_root_set; }

private:
	size_t* root = 0;
	size_t* parent = 0;
	size_t* start = 0;

	std::set<size_t> u_root_set;
};



/*

class Kruskal
{
public:
	class Set_Range
	{
		class Iterator
		{
		public:
			Iterator(size_t current, size_t* parent, bool b_last_reached) : current(current), parent(parent),
				b_last_reached(b_last_reached) {};
			inline void operator++() { b_last_reached = current == parent[current]; current = parent[current]; }
			inline bool operator!=(const Iterator& other) const
				{  return current != other.current || b_last_reached != other.b_last_reached; }
			inline size_t operator*() { return current; }
		private:
			size_t current = 0;
			size_t* parent = 0;
			bool b_last_reached = false;
		};
	public:
		Set_Range(size_t start_i, size_t end_i, size_t* parent) : start_i(start_i), end_i(end_i), parent(parent) {}
		inline Iterator begin() { return Iterator(start_i, parent, false); }
		inline Iterator end() { return Iterator(end_i, parent, true); }
	private:
		size_t start_i = 0;
		size_t end_i = 0;
		size_t* parent = 0;
	};

public:
	Kruskal(size_t size)
	{
		root = new size_t[size];
		parent = new size_t[size];
		start = new size_t[size];

		this->size = new size_t[size];
		sum = new size_t[size];
		min = new size_t[size];
		max = new size_t[size];
		for (size_t i = 0; i < size; ++i)
		{
			root[i] = parent[i] = start[i] = i;

			sum[i] = min[i] = max[i] = i;
			this->size[i] = 1;
		}
	}
	~Kruskal()
	{
		delete[] root;
		delete[] parent;
		delete[] start;

		delete[] size;
		delete[] min;
		delete[] max;
	}
	size_t find(size_t i)
	{
		if (root[i] == i)
			return i;
		return root[i] = find(root[i]);
	}

	void union1(size_t i, size_t j)
	{
		size_t a = find(i);
		size_t b = find(j);
		if (a == b)
			return;
		root[a] = b;
		parent[a] = start[b];
		start[b] = start[a];
		u_root_set.erase(a);
		u_root_set.insert(b);

		size[b] += size[a];
		sum[b] += sum[a];
		min[b] = min[b] > min[a] ? min[a] : min[b];
		max[b] = max[b] < max[a] ? max[a] : max[b];
	}

	inline Set_Range get_set_range(size_t i)
		{ return Set_Range(start[root[i]], root[i], parent); }

	inline const std::set<size_t>& get_u_root_set() { return u_root_set; }

	inline size_t get_size(size_t i) { return size[root[i]]; }
	inline size_t get_sum(size_t i) { return sum[root[i]]; }
	inline size_t get_min(size_t i) { return min[root[i]]; }
	inline size_t get_max(size_t i) { return max[root[i]]; }

private:
	size_t* root = 0;
	size_t* parent = 0;
	size_t* start = 0;

	std::set<size_t> u_root_set;

	size_t* size = 0;
	size_t* sum = 0;
	size_t* min = 0;
	size_t* max = 0;
	
};

*/
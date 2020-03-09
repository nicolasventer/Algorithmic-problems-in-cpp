#include <algorithm>
#include <vector>

template<typename T>
struct Sorted_data
{
	Sorted_data(T value, int index) : value(value), index(index) {} 
	
	T value;
	
	int index;
	int target;
	
	static inline bool sort_with_value(Sorted_data data1, Sorted_data data2)
	{
		return data1.value < data2.value;
	}
	
	static inline bool sort_with_index(Sorted_data data1, Sorted_data data2)
	{
		return data1.index < data2.index;
	}
	
	static inline std::vector<Sorted_data<T>> get_sort_vector(std::vector<T> v, bool b_unsort)
	{
		return get_sort_vector(&v[0], v.size(), b_unsort);
	}

	static std::vector<Sorted_data<T>> get_sort_vector(T* v, int size, bool b_unsort)
	{
		std::vector<Sorted_data<T>> s_v;
		for (int i=0; i<size; i++)
			s_v.push_back(Sorted_data<T>(v[i], i));
		std::sort(s_v.begin(), s_v.end(), Sorted_data<T>::sort_with_value);
		for (int i=0; i<size; i++)
			s_v[i].target = i;
		if (b_unsort)
			std::sort(s_v.begin(), s_v.end(), Sorted_data<T>::sort_with_index);
		return s_v;
	}
};
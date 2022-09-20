#pragma once

#include <vector>

template <typename T>
class IterableVector
{
public:
	void add(T type) 
	{
		if (editable)
		{
			count++;
			container.push_back(type);
		}
	}

	T& getNext() 
	{
		editable = false;
		count--;
		counterChecher();

		return container[count];
	}

	T& getId(short id) 
	{
		return container[id];
	}

	T& getId(size_t id)
	{
		return container[id];
	}

	size_t size() const
	{
		return container.size();
	}

private:
	std::vector<T> container;
	int count = 0;
	bool editable = true;

	inline void counterChecher() 
	{
		if (count < 0)
			count = container.size() - 1;
	}
};




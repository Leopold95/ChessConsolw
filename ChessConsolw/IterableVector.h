#pragma once

#include <vector>

template <typename T>
class IterableVector
{
public:
	void add(T);
	T getNext();
	T getId(size_t);
	size_t size();

private:
	std::vector<T> container;
	int count = 0;
	bool editable = true;

	inline void counterChecher();
};



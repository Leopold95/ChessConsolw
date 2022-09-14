#pragma once

#include <vector>

template <typename T>
class IterableVector : public std::vector
{
public:
	void add(T);
	T getNext();
	T getId(size_t);
	size_t size();

private:
	std::vector<T> container;
	int count = -1;
	bool editable = true;

	inline void counterChecher();
};



#include "IterableVector.h"

template<typename T>
void IterableVector<T>::add(T)
{
	if (editable)
	{
		count++;
		container.push_back(type);
	}
}

template<typename T>
T IterableVector<T>::getNext()
{
	editable = false;
	count--;
	counterChecher();

	return container[count];
}

template<typename T>
T IterableVector<T>::getId(size_t id)
{
	return container[id];
}

template<typename T>
size_t IterableVector<T>::size()
{
	return container.size();
}

template<typename T>
inline void IterableVector<T>::counterChecher()
{
	if (count < 0)
		count = container.size() - 1;
}
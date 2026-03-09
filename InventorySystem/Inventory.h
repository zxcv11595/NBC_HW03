#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

struct Item
{
private:
	string	_name;
	int		_price;

public:
	Item() : _name(""), _price(0) {}
	Item(string name, int price) : _name(name), _price(price) {}

	string GetName() const { return _name; }
	int GetPrice() const { return _price; }
};

template <typename T>
class Inventory
{
private:
	T*		_pItems;
	int		_capacity;
	int		_size;

public:
	Inventory();
	Inventory(int capacity);
	Inventory(const Inventory<T>& other);
	~Inventory();

	void AddItem(const T& item);
	void RemoveLastItem();

	void Assign(const Inventory<T>& other);

	void Resize(int newCapacity);

	int GetSize() const;
	int GetCapacity() const;

	void SortItem();

	void PrintAllItems() const;
};

template<typename T>
Inventory<T>::Inventory()
	: _pItems(nullptr), _size(0), _capacity(10)
{
	assert(_capacity >= 0);

	_pItems = new T[_capacity];
}

template<typename T>
Inventory<T>::Inventory(int capacity)
	: _pItems(nullptr), _size(0), _capacity(capacity)
{
	assert(_capacity >= 0);

	_pItems = new T[_capacity];
}
template<typename T>
Inventory<T>::Inventory(const Inventory<T>& other)
{
	_capacity = other._capacity;
	_size = other._size;
	_pItems = new T[_capacity];
	for (int i = 0; i < _size; ++i)
		_pItems[i] = other._pItems[i];
}

template<typename T>
Inventory<T>::~Inventory()
{
	if (_pItems)
		delete[] _pItems;
}

template<typename T>
void Inventory<T>::AddItem(const T& item)
{
	if (_size == _capacity)
	{
		_capacity = (_capacity == 0 ? 1 : _capacity * 2);
		Resize(_capacity);
	}

	_pItems[_size++] = item;
}

template<typename T>
void Inventory<T>::RemoveLastItem()
{
	if (_size > 0)
		--_size;
	else
		cout << "인벤토리가 비어있습니다." << endl;
}

template<typename T>
void Inventory<T>::Assign(const Inventory<T>& other)
{
	if (_pItems)
		delete[] _pItems;

	_capacity = other._capacity;
	_size = other._size;
	_pItems = new T[_capacity];
	for (int i = 0; i < _size; ++i)
		_pItems[i] = other._pItems[i];
}

template<typename T>
void Inventory<T>::Resize(int newCapacity)
{
	assert(newCapacity >= _size);

	T* tempItems = new T[newCapacity];
	for (int i = 0; i < _size; ++i)
	{
		tempItems[i] = _pItems[i];
	}

	delete[] _pItems;

	_pItems = tempItems;

	_capacity = newCapacity;
}

template<typename T>
int Inventory<T>::GetSize() const
{
	return _size;
}

template<typename T>
int Inventory<T>::GetCapacity() const
{
	return _capacity;
}

inline bool CompareItemByPrice(const Item& a, const Item& b)
{
	return a.GetPrice() > b.GetPrice();
}

template<typename T>
void Inventory<T>::SortItem()
{
	sort(_pItems, _pItems + _size, CompareItemByPrice);
}

template<typename T>
void Inventory<T>::PrintAllItems() const
{
	for (int i = 0; i < _size; ++i)
	{
		cout << "[이름: " << _pItems[i].GetName() << ", 가격: " << _pItems[i].GetPrice() << "G]" << endl;
	}
}

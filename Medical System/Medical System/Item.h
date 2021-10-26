#pragma once

enum STATE { Empty, Full, Deleted };

template<class T, class K>
class Item
{
	public:
		T data;
		K key;
		STATE flag;
		Item() : flag(STATE.Empty) {}
		Item(T d, K k, STATE f) : this->data = d, this->key = k, this->flag = f {}
};
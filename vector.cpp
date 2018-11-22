#include <iostream>
using namespace std;

template<typename T>
struct vector {
	T* ele;
	int _size;
	int cap;
	vector() {
		_size = 0;
		cap = 32;
		ele = new T[cap];
	}
	~vector() {
		delete[] ele;
	}
	int size() {
		return _size;
	}
	int isfull() {
		return _size == cap;
	}
	bool empty() {
		return !_size;
	}
	void push_back(T e) {
		if (isfull()) resize(cap * 2);
		ele[_size++] = e;
	}
	void resize(int ncap) {
		T *tmp = new T[ncap];
		for (int i = 0; i < _size; i++)
			tmp[i] = ele[i];
		delete[] ele;
		ele = tmp;
		cap = ncap;
	}
	void claer() {
		_size = 0;
	}
	void pop_back() {
		_size--;
	}
	T& operator [] (int idx) {
		return ele[idx];
	}
	T operator [] (int idx) const {
		return ele[idx];
	}
};

int main()
{
	vector<int> v;
	for (int i = 1; i <= 10; i++)
		v.push_back(i);
	v.pop_back();
	v.pop_back();
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}
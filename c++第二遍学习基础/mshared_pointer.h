#pragma once

#include<iostream>
#include<map>
using namespace std;

template<class _Ty>
class Mshared_ptr {
public:
	Mshared_ptr(_Ty* ptr = NULL)
		:_ptr(ptr){
		if (_ptr) {
			_count[_ptr]++;
		}
	}

	Mshared_ptr(Mshared_ptr<_Ty>& _Other) {
		_ptr = _Other._ptr;
		_count[_ptr]++;
	}

	Mshared_ptr& operator = (Mshared_ptr<_Ty>& _Other) {
		if (_ptr != _Other._ptr) {
			if (--_count[_ptr] == 0) {
				std::cout << "Delete object!" << endl;
				delete _ptr;
			}
			_ptr = _Other._ptr;
			_count[_ptr]++;
		}
		return *this;
	}
	~Mshared_ptr() {
		reset();
	}

	_Ty* get() {
		return _ptr;
	}
	void reset() {
		if (unique()) {
			delete _ptr;
		}
		else {
			_count[_ptr]--;
		}
		_ptr = NULL;
	}
	//判断智能指针是否独立 计数器是否是1
	bool unique() {
		return _count[_ptr] == 1;
	}

	int use_count() {
		if (_ptr) return _count[_ptr];
		else return 0;
	}

	_Ty operator[](int index) {
		return _ptr[index];
	}
	_Ty& operator*() {
		return *_ptr;
	}
	_Ty* operator->() {
		return _ptr;
	}
	operator bool() {
		return _ptr != NULL;
	}

private:
	_Ty* _ptr;
	static map<_Ty*, int> _count;
};


//静态成员初始化
template<class _Ty>
map<_Ty*, int> Mshared_ptr<_Ty>::_count = map<_Ty*, int>();


namespace lcl
{
	template<class T>
	class shared_ptr
	{
	public:
		//RAII  explicit  防止隐式构造
		explicit shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
		{}
		~shared_ptr()
		{
			if (--(*_pcount) == 0)
			{
				if (_ptr != nullptr)
				{
					cout << "delete: " << _ptr << endl;
					delete _ptr;
					_ptr = nullptr;
				}
				delete _pcount;
				_pcount = nullptr;
			}
		}
		shared_ptr(shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			(*_pcount)++;
		}
		shared_ptr& operator=(shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr) //管理同一块空间的对象之间无需进行赋值操作
			{
				if (--(*_pcount) == 0) //将管理的资源对应的引用计数--
				{
					cout << "delete: " << _ptr << endl;
					delete _ptr;
					delete _pcount;
				}
				_ptr = sp._ptr;       //与sp对象一同管理它的资源
				_pcount = sp._pcount; //获取sp对象管理的资源对应的引用计数
				(*_pcount)++;         //新增一个对象来管理该资源，引用计数++
			}
			return *this;
		}

		shared_ptr& operator=(T* ptr) {

		}
		//获取引用计数
		int use_count()
		{
			return *_pcount;
		}
		//可以像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;      //管理的资源
		int* _pcount; //管理的资源对应的引用计数
	};
}

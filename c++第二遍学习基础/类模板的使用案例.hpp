#pragma once
#include<iostream>
#include<string>
using namespace std;


template<class T>
class MyArray {

public:
	MyArray(int capacity = 4) {
		m_Capacity = capacity;
		m_Arr = new T[capacity];
		m_Size = 0;
		//cout << "构造函数的调用" << endl;
	}
	//拷贝构造函数
	MyArray(const MyArray& arr) {
		//cout << "拷贝构造函数的调用" << endl;

		//if (this->m_Arr) delete this->m_Arr;
		this->m_Arr = new T[arr.m_Capacity];
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		if (!this->m_Arr) {
			cout << "new fail!" << endl;
			return;
		}
		//吧元素拷贝对象上面
		for (int i = 0; i < this->m_Size; i++) {
			this->m_Arr[i] = arr.m_Arr[i];
		}
	}
	//重载运算符等号
	MyArray& operator=(const MyArray& arr) {
		//cout << "重载等号的调用" << endl;

		if (this->m_Arr) delete this->m_Arr;
		this->m_Arr = new T[arr.m_Capacity];
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		if (!this->m_Arr) {
			cout << "new fail!" << endl;
		}
		else {
			for (int i = 0; i < this->m_Size; i++) {
				this->m_Arr[i] = arr.m_Arr[i];
			}
		}
		return *this;

	}
	//扩容 如果容量不够
	void Check_Capacity() {
		if (this->m_Size == this->m_Capacity) {
			cout << "容量满了 需要扩容!" << endl;
			delete this->m_Arr;
			this->m_Capacity *= 2;
			this->m_Arr = new T[this->m_Capacity];
			cout << "扩容成功！" << endl;
		}
	}
	//重载运算符[]  也可以作为左值存在
	T& operator[](int i) {
		return this->m_Arr[i];
	}
	//尾插
	void PuchBack(T t) {
		this->Check_Capacity();
		this->m_Arr[this->m_Size] = t;
		m_Size += 1;
	}
	//尾删
	void PuchPop() {
		this->m_Size--;
	}

	//获取容量
	int Get_Capacity() {
		return this->m_Capacity;
	}
	//获取大小
	int Get_Size() {
		return this->m_Size;
	}

	//打印
	void PrintArr() {
		for (int i = 0; i < m_Size; i++) {
			cout << m_Arr[i] << " ";
		}
		cout << endl;
	}
	~MyArray() {
		if (m_Arr) {
			//cout << "析构函数的调用" << endl;

			delete m_Arr;
			m_Arr = NULL;
			return;
		}
	}
private:
	T* m_Arr;
	int m_Capacity;
	int m_Size;
};
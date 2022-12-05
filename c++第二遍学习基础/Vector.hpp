#pragma once

#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

//命名空间
namespace LCL {


	template <typename T>
	class Vector {
	public:
		//构造拷贝
		Vector();
		~Vector();

		void push_back(T value);//插入
		void pop_back();//删除末端元素
		void show()const;//显示数据
		void reverse(int size);//预留空间
		void resize(int size);//重新设定大小
		void resize(int size,int value);//重新设定大小
		int size()const;//获取大小
		int capacity()const;//获取容量
		T* data()const;//获取内存地址
		void swap(Vector<T>& other);//交换两个容器
		T& at(const int index)const;//获取下标对应的值
		T& operator [](int index);//重载运算符 []
		Vector<T>& operator =(const Vector<T>& other);//重载运算符 =
		bool empty()const;//判断是否未空
		void clear();//清空容器
		T& front();//获取第一个元素
		T& back();//获取最后一个元素
		class Iterator {
			//析构  构造
		public:
			Iterator():m_Iterator(NULL) {}
			Iterator(T* iterator):m_Iterator(iterator){}
			~Iterator() {
				m_Iterator = NULL;
			}

			bool operator ==(const Iterator& other) {
				return m_Iterator == other.m_Iterator;
			}

			bool operator !=(const Iterator& other) {
				return m_Iterator != other.m_Iterator;
			}

			Iterator& operator +=(int num) {
				m_Iterator += num;
				return *this;
			}

			Iterator& operator -=(int num) {
				m_Iterator -= num;
				return *this;
			}

			Iterator& operator =(const Iterator& other) {
				m_Iterator = other.m_Iterator;
				return *this;
			}
			//前置++
			Iterator& operator ++() {
				m_Iterator+=1;
				return *this;
			}
			//后置++
			Iterator operator ++(int) {
				Iterator it = *this;
				m_Iterator+=1;
				return it;
			}

			//前置--
			Iterator& operator --() {
				m_Iterator-=1;
				return *this;
			}
			//后置--
			Iterator& operator --(int) {
				Iterator it = *this;
				m_Iterator-=1;
				return it;
			}

			Iterator operator +(int num) {
				Iterator it = *this;
				it.m_Iterator += num;
				return it;
			}

			Iterator operator -(int num) {
				Iterator it = *this;
				it.m_Iterator -= num;
				return it;
			}

			int operator -(const Iterator& other) {
				return m_Iterator - other.m_Iterator;
			}

			int operator +(const Iterator& other) {
				return m_Iterator + other.m_Iterator;
			}

			T& operator* () {
				return *m_Iterator;
			}

			T* operator -> () {
				return m_Iterator;
			}

		private:
			T* m_Iterator;
		};
		
		Iterator begin();
		Iterator end();

		Iterator find(const T& val);

		Iterator insert(Iterator it, const T& val);
		Iterator insert(Iterator it,int n, const T& val);

		Iterator erase(Iterator it);
	private:
		T* m_Data;
		int m_Size;
		int m_Capacity;
		

		void Add_Capacity();//增容
	};

	template <typename T>
	typename Vector<T>::Iterator Vector<T>::begin() {
		Vector<T>::Iterator it(data());
		return it;
	}

	template <typename T>
	typename Vector<T>::Iterator Vector<T>::end() {
		Vector<T>::Iterator it(data() + m_Size);
		return it;
	}

	template <typename T>
	typename Vector<T>::Iterator Vector<T>::find(const T& val) {
		for (Vector<T>::Iterator it = begin(); it != end(); it++) {
			if (*it == val) {
				return it;
			}
		}
		return end();
	}


	template <typename T>
	typename Vector<T>::Iterator Vector<T>::insert(Vector<T>::Iterator it, const T& val) {
		return insert(it, 1, val);
	}


	template <typename T>
	typename Vector<T>::Iterator Vector<T>::insert(Vector<T>::Iterator it, int n, const T& val) {
		int size = it - begin();
		cout << size << endl;
		while (m_Capacity < m_Size + n) {
			Add_Capacity();
		}
		for (int i = m_Size - 1; i >= size; i--) {
			m_Data[i + n] = m_Data[i];
		}
		for (int i = 0; i < n; i++) {
			m_Data[i + size] = val;
		}
		m_Size += n;
		return it;
	}

	template <typename T>
	typename Vector<T>::Iterator Vector<T>::erase(Vector<T>::Iterator it) {
		int sz = it - begin();
		for (int i = sz + 1; i < m_Size; i++) {
			m_Data[i - 1] = m_Data[i];
		}
		m_Size--;
		return it;
	}



	template <typename T>
	Vector<T>::Vector():m_Data(NULL),m_Size(0),m_Capacity(0) {}

	template <typename T>
	Vector<T>::~Vector() {
		if (m_Data) {
			delete[] m_Data;
			m_Data = NULL;
			m_Size = 0;
			m_Capacity = 0;
		}
	}



	template <typename T>
	void Vector<T>::push_back(T value) {
		
		if (m_Size == m_Capacity) {
			Add_Capacity();
		}
		m_Data[m_Size++] = value;
	}
	

	template <typename T>
	void Vector<T>::pop_back() {
		if (m_Data) {
			m_Size--;
		}
		else {
			throw std::logic_error("Vector is Empty!");
		}
	}
	

	template <typename T>
	void Vector<T>::show() const{
		std::cout << "array" << std::endl;
		std::cout << "大小：" << size() << "," << "容量：" << capacity() << std::endl;
		for (int i = 0; i < m_Size; i++) {
			std::cout << m_Data[i] << " ";
		}
		std::cout << std::endl;
	}

	template <typename T>
	void Vector<T>::Add_Capacity() {
		m_Capacity = m_Capacity == 0 ? 2 : m_Capacity * 2;
		T* newdata = new T[m_Capacity];
		if (!newdata) return;

		for (int i = 0; i < m_Size; i++) {
			*(newdata + i) = m_Data[i];
		}
		delete[] m_Data;
		m_Data = newdata;
	}

	template <typename T>
	void Vector<T>::reverse(int size) {
		if (size <= m_Size) {
			m_Size = size;
		}
		else if (size <= m_Capacity) {
			for (int i = m_Size; i < size; i++) {
				m_Data[i] = T();
			}
		}
		else {
			while (size > m_Capacity) {
				Add_Capacity();
			}
		}
	}

	//重新设定大小
	template <typename T>
	void Vector<T>::resize(int size) {
		if (size > m_Capacity || size <= m_Capacity) {
			while (size > m_Capacity) {
				Add_Capacity();
			}
			for (int i = m_Size; i < size; i++) {
				m_Data[i] = 0;
			}
		}
		m_Size = size;
	}

	template <typename T>
	void Vector<T>::resize(int size,int value) {
		
		if (size > m_Capacity || size <= m_Capacity) {
			while (size > m_Capacity) {
				Add_Capacity();
			}
			for (int i = m_Size; i < size; i++) {
				m_Data[i] = value;
			}
		}
		m_Size = size;
	}
	//获取大小
	template <typename T>
	int Vector<T>::size()const {
		return m_Size;
	}
	//获取容量
	template <typename T>
	int Vector<T>::capacity()const {
		return m_Capacity;
	}
	//获取内存地址
	template <typename T>
	T* Vector<T>::data()const {
		return m_Data;
	}

	//交换两个容器的内容
	template <typename T>
	void Vector<T>::swap(Vector<T>& other) {
		T* data = other.m_Data;
		int size = other.m_Size;
		int capacity = other.m_Capacity;

		other.m_Data = m_Data;
		other.m_Capacity = m_Capacity;
		other.m_Size = m_Size;

		m_Data = data;
		m_Capacity = capacity;
		m_Size = size;
	}

	template <typename T>
	T& Vector<T>::at(const int index)const {
		if (index >= 0 && index < m_Size) {
			return m_Data[index];
		}
		else {
			throw std::logic_error("index fail!");
		}
	}

	//重载运算符 =
	template <typename T>
	Vector<T>& Vector<T>::operator =(const Vector<T>& other) {
		T* newdata = new T[other.m_Capacity];
		std::cout << other.m_Data[1] << std::endl;
		for (int i = 0; i < other.m_Size; i++) {
			*(newdata + i) = other.m_Data[i];
		}
		delete[] m_Data;
		m_Data = newdata;
		m_Size = other.m_Size;
		m_Capacity = other.m_Capacity;
		return *this;
	}

	template <typename T>
	T& Vector<T>::operator [](int index) {
		if (index >= 0 && index < m_Size) {
			return m_Data[index];
		}
		else {
			throw std::logic_error("index fail!");
		}
	}

	template <typename T>
	bool Vector<T>::empty()const {
		return m_Size == 0;
	}


	template <typename T>
	void Vector<T>::clear() {
		m_Size = 0;
		m_Capacity = 0;
	}

	//获取第一个元素
	template <typename T>
	T& Vector<T>::front() {
		if (m_Size > 0) {
			return m_Data[0];
		}
		else {
			throw std::logic_error("Vector is Empty!");
		}
	}

	//获取最后一个元素
	template <typename T>
	T& Vector<T>::back() {
		if (m_Size > 0) {
			return m_Data[m_Size-1];
		}
		else {
			throw std::logic_error("Vector is Empty!");
		}
	}


}


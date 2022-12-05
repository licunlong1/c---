#pragma once

#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

//�����ռ�
namespace LCL {


	template <typename T>
	class Vector {
	public:
		//���쿽��
		Vector();
		~Vector();

		void push_back(T value);//����
		void pop_back();//ɾ��ĩ��Ԫ��
		void show()const;//��ʾ����
		void reverse(int size);//Ԥ���ռ�
		void resize(int size);//�����趨��С
		void resize(int size,int value);//�����趨��С
		int size()const;//��ȡ��С
		int capacity()const;//��ȡ����
		T* data()const;//��ȡ�ڴ��ַ
		void swap(Vector<T>& other);//������������
		T& at(const int index)const;//��ȡ�±��Ӧ��ֵ
		T& operator [](int index);//��������� []
		Vector<T>& operator =(const Vector<T>& other);//��������� =
		bool empty()const;//�ж��Ƿ�δ��
		void clear();//�������
		T& front();//��ȡ��һ��Ԫ��
		T& back();//��ȡ���һ��Ԫ��
		class Iterator {
			//����  ����
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
			//ǰ��++
			Iterator& operator ++() {
				m_Iterator+=1;
				return *this;
			}
			//����++
			Iterator operator ++(int) {
				Iterator it = *this;
				m_Iterator+=1;
				return it;
			}

			//ǰ��--
			Iterator& operator --() {
				m_Iterator-=1;
				return *this;
			}
			//����--
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
		

		void Add_Capacity();//����
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
		std::cout << "��С��" << size() << "," << "������" << capacity() << std::endl;
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

	//�����趨��С
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
	//��ȡ��С
	template <typename T>
	int Vector<T>::size()const {
		return m_Size;
	}
	//��ȡ����
	template <typename T>
	int Vector<T>::capacity()const {
		return m_Capacity;
	}
	//��ȡ�ڴ��ַ
	template <typename T>
	T* Vector<T>::data()const {
		return m_Data;
	}

	//������������������
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

	//��������� =
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

	//��ȡ��һ��Ԫ��
	template <typename T>
	T& Vector<T>::front() {
		if (m_Size > 0) {
			return m_Data[0];
		}
		else {
			throw std::logic_error("Vector is Empty!");
		}
	}

	//��ȡ���һ��Ԫ��
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


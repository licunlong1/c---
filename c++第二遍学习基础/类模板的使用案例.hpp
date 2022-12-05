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
		//cout << "���캯���ĵ���" << endl;
	}
	//�������캯��
	MyArray(const MyArray& arr) {
		//cout << "�������캯���ĵ���" << endl;

		//if (this->m_Arr) delete this->m_Arr;
		this->m_Arr = new T[arr.m_Capacity];
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		if (!this->m_Arr) {
			cout << "new fail!" << endl;
			return;
		}
		//��Ԫ�ؿ�����������
		for (int i = 0; i < this->m_Size; i++) {
			this->m_Arr[i] = arr.m_Arr[i];
		}
	}
	//����������Ⱥ�
	MyArray& operator=(const MyArray& arr) {
		//cout << "���صȺŵĵ���" << endl;

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
	//���� �����������
	void Check_Capacity() {
		if (this->m_Size == this->m_Capacity) {
			cout << "�������� ��Ҫ����!" << endl;
			delete this->m_Arr;
			this->m_Capacity *= 2;
			this->m_Arr = new T[this->m_Capacity];
			cout << "���ݳɹ���" << endl;
		}
	}
	//���������[]  Ҳ������Ϊ��ֵ����
	T& operator[](int i) {
		return this->m_Arr[i];
	}
	//β��
	void PuchBack(T t) {
		this->Check_Capacity();
		this->m_Arr[this->m_Size] = t;
		m_Size += 1;
	}
	//βɾ
	void PuchPop() {
		this->m_Size--;
	}

	//��ȡ����
	int Get_Capacity() {
		return this->m_Capacity;
	}
	//��ȡ��С
	int Get_Size() {
		return this->m_Size;
	}

	//��ӡ
	void PrintArr() {
		for (int i = 0; i < m_Size; i++) {
			cout << m_Arr[i] << " ";
		}
		cout << endl;
	}
	~MyArray() {
		if (m_Arr) {
			//cout << "���������ĵ���" << endl;

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
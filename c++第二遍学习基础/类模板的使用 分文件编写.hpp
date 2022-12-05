#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T1,class T2>
class Person1 {
public:
	Person1(T1 name, T2 age);
	void PrintPerson1();

private:
	T1 m_Name;
	T2 m_Age;
};


template<class T1, class T2>
Person1<T1, T2>::Person1(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}

//类外实现类模板的类成员函数
template<class T1, class T2>
void Person1<T1, T2>::PrintPerson1() {
	cout << "姓名：" << m_Name << "\n年龄：" << m_Age << endl;
}
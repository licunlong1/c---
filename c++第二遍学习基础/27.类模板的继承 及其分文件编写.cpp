//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include"��ģ���ʹ�� ���ļ���д.hpp"
//using namespace std;
//
//
////�̳�ģ�常��---------------------------------------------
//template<class T>
//class Base {
//public:
//	T a;
//};
//
////1.�̳и���Ļ� ��Ҫָ������ģ���е�����
//class Son :public Base<int> {
//public:
//	int tree;
//};
//
////2.�̳и���Ļ� �������дָ������ ��ô����Ҳ��Ҫ����ģ��
//template<class T1,class T2>
//class Son1 :public Base<T1> {
//public:
//	T2 tree;
//};
//
////--------------------------------------------------------
////��ģ���г�Ա����������ʵ��
//template<class T1,class T2>
//class Person {
//public:
//	Person(T1 name,T2 age);
//	void PrintPerson();
//private:
//	T1 m_Name;
//	T2 m_Age;
//
//};
////����ʵ����ģ��Ĺ��캯��
//
//template<class T1,class T2>
//Person<T1,T2>::Person(T1 name, T2 age) {
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
////����ʵ����ģ������Ա����
//template<class T1, class T2>
//void Person<T1, T2>::PrintPerson() {
//	cout << "������" << m_Name << "\n���䣺" << m_Age << endl;
//}
//
////������ģ�����Ա����������ʵ��
//void test01() {
//	Person<string, int>p("��˽�", 99);
//	p.PrintPerson();
//}
//
//
////���Է��ļ���д��ģ��   ����ʵ��д�뵽һ���ļ�  ͷ�ļ�����hpp  header  Լ���ĺ�׺��
//void test02() {
//	Person1<string, int>p("��˽�", 99);
//	p.PrintPerson1();
//}
//
//int main() {
//	test01();
//
//	test02();
//	return 0;
//}
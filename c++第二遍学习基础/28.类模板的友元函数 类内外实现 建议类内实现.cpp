//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//template<class T1, class T2> class Person;
//
//template<class T1, class T2>
//void printPerson1(Person<T1, T2>p) {
//	cout << "������" << p.m_Name << "\n���䣺" << p.m_Age << endl;
//
//}
//
//template<class T1,class T2>
//class Person {
//	//ȫ�ֺ���������ʵ��
//	friend void printPerson1<>(Person<T1, T2>p);
//	//ȫ�ֺ���������ʵ��
//	friend void PrintPerson(Person<T1, T2>& p) {
//		cout << "������" << p.m_Name << "\n���䣺" << p.m_Age << endl;
//	}
//	
//public:
//	Person(T1 name,T2 age);
//	
//private:
//	T1 m_Name;
//	T2 m_Age;
//};
//
//template<class T1,class T2>
//Person<T1, T2>::Person(T1 name,T2 age) {
//	this->m_Name = name;
//	this->m_Age = age;
//}
////����ȫ�ֺ�������ʵ��
//void test01() {
//	Person<string, int> p("ţ����",100);
//	PrintPerson(p);
//}
////����ȫ�ֺ�������ʵ��
//void test02() {
//	Person<string, int> p1("ţ����", 220);
//	printPerson1(p1);
//}
//int main() {
//	test01();
//	test02();
//	return 0;
//}
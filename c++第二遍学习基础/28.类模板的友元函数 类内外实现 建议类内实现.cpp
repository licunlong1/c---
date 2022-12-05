//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//template<class T1, class T2> class Person;
//
//template<class T1, class T2>
//void printPerson1(Person<T1, T2>p) {
//	cout << "姓名：" << p.m_Name << "\n年龄：" << p.m_Age << endl;
//
//}
//
//template<class T1,class T2>
//class Person {
//	//全局函数的类外实现
//	friend void printPerson1<>(Person<T1, T2>p);
//	//全局函数的类内实现
//	friend void PrintPerson(Person<T1, T2>& p) {
//		cout << "姓名：" << p.m_Name << "\n年龄：" << p.m_Age << endl;
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
////测试全局函数类内实现
//void test01() {
//	Person<string, int> p("牛牧王",100);
//	PrintPerson(p);
//}
////测试全局函数类外实现
//void test02() {
//	Person<string, int> p1("牛牧王", 220);
//	printPerson1(p1);
//}
//int main() {
//	test01();
//	test02();
//	return 0;
//}
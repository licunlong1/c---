//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include"类模板的使用 分文件编写.hpp"
//using namespace std;
//
//
////继承模板父类---------------------------------------------
//template<class T>
//class Base {
//public:
//	T a;
//};
//
////1.继承父类的话 需要指定父类模板中的类型
//class Son :public Base<int> {
//public:
//	int tree;
//};
//
////2.继承父类的话 如果不想写指定类型 那么子类也需要是类模板
//template<class T1,class T2>
//class Son1 :public Base<T1> {
//public:
//	T2 tree;
//};
//
////--------------------------------------------------------
////类模板中成员函数的类外实现
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
////类外实现类模板的构造函数
//
//template<class T1,class T2>
//Person<T1,T2>::Person(T1 name, T2 age) {
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
////类外实现类模板的类成员函数
//template<class T1, class T2>
//void Person<T1, T2>::PrintPerson() {
//	cout << "姓名：" << m_Name << "\n年龄：" << m_Age << endl;
//}
//
////测试类模板类成员函数的类外实现
//void test01() {
//	Person<string, int>p("猪八戒", 99);
//	p.PrintPerson();
//}
//
//
////测试分文件编写类模板   定义实现写入到一个文件  头文件命名hpp  header  约定的后缀名
//void test02() {
//	Person1<string, int>p("猪八戒", 99);
//	p.PrintPerson1();
//}
//
//int main() {
//	test01();
//
//	test02();
//	return 0;
//}
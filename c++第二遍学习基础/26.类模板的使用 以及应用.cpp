//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
//
////类模板与函数模板的区别就是 ： 类模板不能使用自动推到类型 只能使用指定类型
////---------------------------------------------------------------------------------
//template<class TypeName,class TypeAge>
//class Person {
//public:
//	//构造函数
//	Person(TypeName name, TypeAge age):m_Name(name),m_Age(age) {
//
//	}
//
//	TypeName m_Name;
//	TypeAge m_Age;
//};
////1.指定类型做函数参数传入
//void PrintPerson1(Person<string, int>& p) {
//	cout << "姓名：" << p.m_Name << "\n年龄：" << p.m_Age << endl;
//}
//
////2.参数类型使用模板
//template<typename T1,typename T2>
//void PrintPerson2(Person<T1,T2>&p) {
//	cout << "姓名：" << p.m_Name << "\n年龄：" << p.m_Age << endl;
//	cout << typeid(T1).name() << endl;
//	cout << typeid(T2).name() << endl;
//
//}
//
////3.整体类型使用模板
//template<typename T>
//void PrintPerson3(T& p) {
//	cout << "姓名：" << p.m_Name << "\n年龄：" << p.m_Age << endl;
//	cout << typeid(p).name() << endl;
//
//}
//
//
//void test01() {
//	Person<string,int> p1("孙悟空", 999);
//	PrintPerson1(p1);
//	Person<string, int> p2("猪八戒", 999);
//	PrintPerson2(p2);
//	Person<string, int> p3("唐僧", 999);
//	PrintPerson3(p3);
//
//}
////--------------------------------------------------------------------------------------
//
////类模板的函数创建时机  类模板函数创建时机是调用时才创建  没有创建的时候类模板的成员函数是不存在的
//class Print1 {
//public:
//	void Print11() {
//		cout << "这是person1类的成员函数！" << endl;
//	}
//};
//
//class Print2 {
//public:
//	void Print22() {
//		cout << "这是person2类的成员函数！" << endl;
//	}
//};
//
//template<class T>
//class Print3 {
//public:
//	T obj;
//	void func1() {
//		obj.Print11();
//	}
//	void func2() {
//		obj.Print22();
//	}
//
//};
////测试类模板成员函数的调用时机 创建时机  因为类模板中的成员函数 是不知道T是什么数据类型  
////所以编译阶段并不会创建实际则是在调用时候才会创建成员函数
//void test02() {
//	Print3<Print1> p1;
//	p1.func1();
//	//p1.func2();//类模板类型是Print1所以不可调用Print2类成员的函数
//	Print3<Print2> p2;
//	//p2.func1();//类模板类型是Print2所以不可调用Print1类成员的函数
//	p2.func2();
//	
//}
//
//int main() {
//	test01();
//
//	test02();
//	return 0;
//}
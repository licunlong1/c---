//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
////静态成员变量 类内声明 类外初始化  内存中只有一份 共用 
////静态成员函数也是内存中只有一份 共用   静态成员函数也是有访问权限的
//// 
//// 
//// 
////成员变量和成员函数是分开存储的  空类占用内存1字节  只有非静态成员变量属于类上面的 占用内存 
////非静态成员函数  静态成员变量 静态成员函数  都不属于类上面
//class Person {
//public:
//	static void func() {
//		m_A = 1000;//修改静态成员变量
//		//m_B = 100;//不可以修改  因为不知道这个成员变量属于那个实例化的对象上面 
//		//静态成员变量 一个静态成员变量对多个实例化对象 其他成员变量只能一对一
//		cout << "这是一个静态成员函数！只能访问静态成员变量 不可以访问其他变量！" << endl;
//	}
//
//	//静态成员变量 类内声明
//	static int m_A;
//	int m_B;
//};
////类外加作用域初始化静态成员变量
//int Person::m_A = 100;
//
//void test1() {
//	//访问静态变量的两种方式  因为静态变量再内存中只存储一份  所有实例化对象公用一份  谁的改变都是会有影响的
// 	//1.实例化对象访问
//	Person p1;
//	p1.m_A = 300;
//	cout << p1.m_A << endl;
//	//2.类名作用域访问
//	cout << Person::m_A << endl;
//}
//void test2() {
//	Person p1;
//	cout << p1.m_A << endl;
//	p1.func();
//	cout << Person::m_A << endl;
//}
//
//
//int main() {
//	//test1();
//	test2();
//	return 0;
//}
//

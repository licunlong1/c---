//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//
//class Person {
//public:
//	Person() {
//		cout << "这是一个默认构造函数！" << endl;
//	}
//	Person(int age) {
//		m_Age = age;
//		cout << "这是一个有参构造函数！" << endl;
//	}
//	Person(const Person& p) {
//		m_Age = p.m_Age;
//		cout << "这是一个拷贝构造函数！" << endl;
//	}
//	~Person() {
//		cout << "这是一个析构函数！" << endl;
//	}
//private:
//	int m_Age = 0;
//};
//
////1.已经实例化一个对象了 在创建一个新的对象的话 实例化对象对新对象进行赋值 会调用拷贝构造函数
//void test1() {
//	Person p1;
//	Person p2(p1);
//}
////2.当对象作为函数参数传递的时候会进行值拷贝  实参传递形参 值传递 也会调用拷贝构造函数 拷贝一个临时的新对象
//void Do_Work(Person p) {
//
//}
//
//void test2() {
//	Person p1;
//	Do_Work(p1);//调用函数的同时进行值传递 相当于创建一个临时的变量
//}
////3.当局部对象作为函数的返回值的话 也会调用拷贝构造函数 因为在返回局部对象的同时 编译器创建出一个新的临时变量作为
////函数的返回值 这也是相当于一个拷贝  所以会调用
//Person Do_Work1() {
//	Person p;
//	cout << (int*)&p << endl;
//	return p;
//}
//
//void test3() {
//
//	Person p1 = Do_Work1();
//	cout << (int*)&p1 << endl;
//
//}
//
//
//int main() {
//	//test1();
//	//test2();
//	test3();
//
//	return 0;
//}
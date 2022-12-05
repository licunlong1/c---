//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Person1 {
//public:
//	//构造函数初始化列表  注意冒号的位置
//	Person1(int a,int b,int c):a(a),b(b),c(c){}
//
//	int a;
//	int b;
//	int c;
//};
//
//class Person {
//public:
//	Person() {
//		cout << "这是一个默认构造函数！" << endl;
//	}
//	Person(int age,int height) {
//		m_Age = age;
//		m_Height = new int(height);
//		cout << "这是一个有参构造函数！" << endl;
//	}
//	Person(const Person& p) {
//		cout << "这是一个深拷贝的拷贝构造函数" << endl;
//		this->m_Age = p.m_Age;
//		this->m_Height = new int(*p.m_Height);
//	}
//	~Person() {
//		if (m_Height) {
//			delete m_Height;
//			m_Height = NULL;
//		}
//		cout << "这是一个析构函数！" << endl;
//	}
//	int m_Age = 0;
//	int* m_Height = NULL;
//};
////当你不写拷贝构造函数的话 系统会给你提供一个拷贝构造函数 进行赋值操作
////这个测试案例是错误的 因为进行了浅拷贝的问题 身高是个指针 在堆区开辟的内存 让后p2拷贝了p1 也把堆区开辟空间
////的地址拷贝了过去  让后进行析构的时候呢 先释放的p2  再释放的p1 释放p2的时候已经吧堆区的内存释放掉了
////释放p1的时候会再次释放堆区的内存 形成多次释放 对一块堆区的内存多次释放 导致程序崩溃 这就是浅拷贝
//void test1() {
//	Person p1(18,160);
//
//	cout << "p1的年龄：" << p1.m_Age << "p1的身高：" << *(p1.m_Height) << endl;
//	Person p2(p1);
//	cout << "p2的年龄：" << p2.m_Age << "p2的身高：" << *(p2.m_Height) << endl;
//}
//
////如果属性里面有指针类型 或者堆区开辟的空间的话 一定要自己写拷贝构造函数 进行深拷贝
////深拷贝
//void test2() {
//	Person p1(18, 160);
//
//	cout << "p1的年龄：" << p1.m_Age << "p1的身高：" << *(p1.m_Height) << endl;
//	Person p2(p1);
//	cout << "p2的年龄：" << p2.m_Age << "p2的身高：" << *(p2.m_Height) << endl;
//
//
//}
//int main() {
//	//test1();
//	//test2();
//
//	Person1 p1(10, 20, 100);
//	cout << p1.a << "  " << p1.b << "  " << p1.c << "  " << endl;
//
//	return 0;
//}
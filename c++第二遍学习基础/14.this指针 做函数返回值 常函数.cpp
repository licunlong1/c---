//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Person {
//public:
//	//这种的属于常函数 常函数不可以修改其他成员变量 如果变量前加mutable 就可以变成可以修改的了
//	void func()const {//const 修饰的是this指针 常函数 相当于  const Person* const this
//		//m_Age = 20;//错误 不可修改
//		m_B = 100; //可以修改 因为成员变量前有mutable  可以再常函数中修改其值
//	}
//
//
//	Person(int age):m_Age(age){}
//	Person(const Person& p) :m_Age(p.m_Age) { cout << "这是一个拷贝构造函数！" << endl; }
//
//	Person& PersonAddAge(const Person& p){ 
//		this->m_Age += p.m_Age;
//		return*this;//this指针做函数的返回值 返回的就是调用这个函数的对象本身  如果不加引用 那么就会使用拷贝构造函数
//		//          拷贝构造函数的调用时机 1.就是函数的返回值 作为值的返回 2.对象作为函数的参数 形参 也会调用拷贝构造
//		//          如果函数返回值  形参不加引用 那么就会调用两次拷贝构造函数 形参 返回值各一次=2次
//	}
//	int m_Age = 0;
//	mutable int m_B = 0;
//};
//void test() {
//	Person p1(20);
//	p1.m_B = 20;//特殊变量可以通过实例化对象访问 跟普通变量一样 但是只有特殊变量才能再常函数中使用修改
//	cout << p1.m_B << endl;
//	Person p2 = 20;
//	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
//	cout << "p2的年龄：" << p2.m_Age << endl;
//
//
//	const Person p3(p1);
//	//p3.m_Age = 20;//错误 因为p3是常对象  常对象不能使用成员变量 但是可以使用特殊变量
//	p3.m_B = 100;//这样是可以的 因为m_B是一个特殊的变量 常对象可以进行访问
//	
//	//常对象只能调用常函数  不能使用别的成员函数
//	p3.func();
//	//p3.PersonAddAge(p1);  错误！
//}
//
//int main() {
//	test();
//
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////在你创建一个类的同时 c++ 会给你自动提供三个函数
////默认构造函数
////析构函数
////拷贝构造函数  见test函数
//class Person {
//public:
//	//无参构造函数
//	Person(){
//		cout << "这是一个无参数构造函数！" << endl;
//	}
//	//有参构造函数
//	Person(int age){
//		m_age = age;
//		cout << "这是一个有参数构造函数！" << endl;
//	}
//	Person(string name,int age) {
//		m_age = age;
//		m_Name = name;
//		cout << "这是一个有参数构造函数！" << endl;
//	}
//	//拷贝构造函数
//	//Person(const Person& p) {
//	//	this->m_age = p.m_age;
//	//	cout << "这是一个拷贝构造函数！" << endl;
//	//}
//	~Person(){
//		cout << "这是一个析构函数！" << endl;
//	}
//	int m_age = 0;
//	string m_Name;
//};
//
//void test() {
//	Person p1("张三",20);
//	Person p2(p1);//类里面没有拷贝构造函数  系统自动创建 让后进行赋值操作
//	cout << p2.m_age << endl;
//	cout << p2.m_Name << endl;
//}
//
//int main() {
//	//1.括号法的实例化对象  对象在程序结束后会自动调用析构函数
//	//Person p1;
//	//Person p2(20);
//	//Person p3(p2);
//
//
//	//2.显示法的实例化对象 使用匿名对象进行调用
//	//Person p1 = Person(10);
//	//Person p3 = Person(p1);
//	//Person(p3);不可以这样写  因为这样编译器会认为这是一个创建的对象 名字是p3相当于 Person p3  会提示重定义
//	//Person(10);//相当于匿名函数  使用完直接进行销毁 因为匿名函数没有名字  后序无法使用到他 系统直接析构 系统也会提示
//	//cout << p3.m_age << endl;
//
//	//3.隐式转换法  直接等号赋值 让后等号右边就是对实例化对象属性的赋值操作
//	//Person p4 = 10;
//	//Person p5 = p4;
//	test();
//	return 0;
//}
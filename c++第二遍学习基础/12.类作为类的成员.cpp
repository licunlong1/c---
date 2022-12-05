//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//
//class Phone {
//public:
//	Phone(string name) :m_PName(name) { cout << "这是Phone的构造函数！" << endl; }// 有参构造函数
//	~Phone() {
//		cout << "这是Phone的析构函数！" << endl;
//	}
//	string m_PName;
//};
//
//class Person {
//	
//
//public:
//	//m_Phone(pname)  这一句话相当于创建了一个phone实例化对象 隐式调用的方式 相当于 Phone m_Phone = pname
//	Person(string name,string pname):m_Name(name),m_Phone(pname){ cout << "这是Person的构造函数！" << endl; }//有参构造函数
//	~Person() {
//		cout << "这是Person的析构函数！" << endl;
//	}
//	string m_Name;
//	Phone m_Phone;
//};
//
//
////类作为本类的成员的时候  先构造类成员 后构造本类  析构的顺数是相反的 先析构本类 再析构类成员 
//void test() {
//	Person p1("张三","华为max");
//
//	cout << p1.m_Name << "拿着" << p1.m_Phone.m_PName << endl;
//}
//
//
//
//int main() {
//	test();
//	return 0;
//}
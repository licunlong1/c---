//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//class Person {
//
//public:
//	Person(){}
//	Person(int age,int height):m_Height(height) {
//		m_Age = new int(age);
//	}
//
//	//运算符重载  赋值
//	Person& operator=(const Person& p) {
//		*(this->m_Age) = *(p.m_Age);//不要改变指针的地址 改变指针指向地址的内容 让后返回本身
//		this->m_Height = p.m_Height;
//		return *this;
//	}
//	bool operator==(const Person& p) {
//		if (*m_Age == *(p.m_Age) && m_Height == p.m_Height) {
//			return true;
//		}
//		return false;
//	}
//	bool operator!=(const Person& p) {
//		if (*m_Age != *(p.m_Age) || m_Height != p.m_Height) {
//			return true;
//		}
//		return false;
//	}
//	~Person() {
//		if (m_Age) {
//			delete m_Age;
//			return;
//		}
//	}
//
//	//指针维护的年龄的数据
//	int* m_Age;
//	//用户的身高
//	int m_Height;
//};
//
////测试赋值运算符
////void test1() {
////	Person p1(18);
////	Person p2(20);
////	Person p3(30);
////	p2 = p1;
////	p2 = p1 = p3;
////	cout << "p1的年龄：" << *(p1.m_Age) << endl;
////	cout << "p2的年龄：" << *(p2.m_Age) << endl;
////	cout << "p3的年龄：" << *(p3.m_Age) << endl;
////
////}
//
////测试关系运算符
//void test01() {
//	Person p1(18, 160);
//	Person p2(20, 160);
//	Person p3(30, 173);
//	
//
//	cout << "p1的年龄：" << *(p1.m_Age) << "   p1的身高：" << (p1.m_Height) << endl;
//	cout << "p2的年龄：" << *(p2.m_Age) << "   p2的身高：" << (p2.m_Height) << endl;
//	cout << "p3的年龄：" << *(p3.m_Age) << "   p3的身高：" << (p3.m_Height) << endl;
//
//	p3 = p1;
//	if (p3 == p1) {
//		cout << "p1和p3两个人是相等的" << endl;
//	}
//	else {
//		cout << "p1和p3两个人是不相等的" << endl;
//	}
//	if (p2 != p1) {
//		cout << "p1和p2两个人是不相等的" << endl;
//	}
//	else {
//		cout << "p1和p3两个人是相等的" << endl;
//	}
//
//}
//
//
////重载函数括号运算符
//class My_Printf{
//public:
//	My_Printf(int num):m_Num(num){}
//	string operator()(string text) {
//		
//		cout << text << endl;
//		return to_string(text.size());
//		
//	}
//	int m_Num;
//};
//
//class ADD:public Person {
//public:
//	ADD(int n):m_Num(n){}
//	void operator()(const ADD& a) {
//		cout << m_Num << endl;
//	}
//	ADD& operator()(int num) {
//		m_Num += num;
//		return *this;
//	}
//	int m_Num;
//};
//
////测试函数括号运算符  这种函数括号重载称之为仿函数
//void test02() {
//	My_Printf myprintf1(10);
//	myprintf1(myprintf1(myprintf1("hello bit！"))); //使用起来非常像函数 非常的灵活 没有固定的写法
//	myprintf1(myprintf1(myprintf1("43")));
//
//	My_Printf(1)("1231231");
//	ADD a1(10);
//	a1(a1(30));
//
//	My_Printf myprintf2(10);
//	//继承包含运算符重载 但是最好不要使用
//	//if (myprintf1 == myprintf2) cout << "两个数相等" << endl;
//	//if (myprintf1 != myprintf2) cout << "两个数相等" << endl;
//	//这样是不正确的  非静态成员变量必须引用实例化对象
//	//cout << ADD::m_Num << endl;
//}
//int main() {
//	//test01();
//	test02();
//
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//
//class Person {
//	//friend Person operator+(const Person& p, const Person& p1);
//	friend ostream& operator<<(ostream& cout,Person p);
//	friend void testAdd();
//public:
//	Person() {}
//	//初始化列表
//	Person(int age,int height):m_Age(age),m_Height(height){}
//	Person(const Person& p):m_Age(p.m_Age), m_Height(p.m_Height)
//	{ cout << "这是Person的拷贝构造函数！" << endl; }
//	//重载函数返回是一个拷贝对象  无引用
//	Person operator +(const Person& p) {
//		Person temp;
//		temp.m_Age = this->m_Age + p.m_Age;
//		temp.m_Height = this->m_Height + p.m_Height;
//		return temp;
//	}
//	//前置++
//	Person& operator++() {
//		this->m_Age++;
//		this->m_Height++;
//		return *this;
//	}
//	//后置++
//	Person operator++(int) {
//		//cout << 1 << endl;
//		Person temp = *this;
//		//cout << 1 << endl;
//		this->m_Age++;
//		this->m_Height++;
//		return temp;
//	}
//private:	 
//
//	int m_Age;
//	int m_Height;
//};
//
//////全局函数的重载
////Person operator+( const Person&p,const Person& p1) {
////	Person temp;
////	temp.m_Age = p.m_Age + p1.m_Age;
////	temp.m_Height = p.m_Height + p1.m_Height;
////	return temp;
////}
//
////重载输出运算符  << 左移运算符  只能在全局函数中重载
//ostream& operator<<(ostream& cout,Person p) {
//	cout << "年龄：" << p.m_Age << "   身高：" << p.m_Height << endl;
//	//cout << p.m_Age;
//	return cout;
//}
////测试重载运算符
//void testAdd() {
//	Person p1(10, 50);
//	Person p2(p1);//这里也会调用拷贝构造函数
//	//cout << p2.m_Age << "   " << p2.m_Height << endl;
//	////类成员函数的重载+号的本质
//	//Person p3 = p1.operator+(p2);
//
//	////全局函数的重载+号的本质
//	//Person p3 = operator+(p1, p2);
//
//	Person p3 = p1 + p2;//这里也会调用拷贝构造函数
//
//	//cout << p3.m_Age << "   " << p3.m_Height << endl;
//	//cout << p1.m_Age << "   " << p1.m_Height << endl;
//	//重载输出运算符之后的效果  链式访问  重载左移运算符函数 
//	//有输出流的返回值才可链式访问  return cout  类型 ostream&
//	cout << p3 << p2 << p1;
//	cout << ++p3;
//	cout << p3++;
//	cout << p3;
//}
//
//int main() {
//	testAdd();
//
//	return 0;
//}
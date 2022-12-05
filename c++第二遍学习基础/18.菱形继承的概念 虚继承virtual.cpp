//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class animal {
//public:
//	//animal(int age) {
//	//	m_Age = 10;
//	//}
//	int m_Age = 10;
//};
//class Sheep :virtual public animal {
//
//};
//
//class Tuo :virtual public animal {
//
//};
//
//class SheepTuo :public Sheep, public Tuo {
//
//};
//
//void test() {
//	SheepTuo st;
//	//这个菱形继承 同种变量 内存中存储了两份 但是实际没必要存储两份 浪费了空间 实现虚继承来解决
//	st.Sheep::m_Age = 18;
//	st.Tuo::m_Age = 1000;
//	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
//	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
//	cout << "st.Tuo::animal::m_Age = " << st.Tuo::animal::m_Age << endl;
//	cout << sizeof(st) << endl;
//
//}
//
//int main() {
//	test();
//
//	return 0;
//}
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
//	//������μ̳� ͬ�ֱ��� �ڴ��д洢������ ����ʵ��û��Ҫ�洢���� �˷��˿ռ� ʵ����̳������
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
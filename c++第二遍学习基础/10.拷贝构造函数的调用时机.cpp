//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//
//class Person {
//public:
//	Person() {
//		cout << "����һ��Ĭ�Ϲ��캯����" << endl;
//	}
//	Person(int age) {
//		m_Age = age;
//		cout << "����һ���вι��캯����" << endl;
//	}
//	Person(const Person& p) {
//		m_Age = p.m_Age;
//		cout << "����һ���������캯����" << endl;
//	}
//	~Person() {
//		cout << "����һ������������" << endl;
//	}
//private:
//	int m_Age = 0;
//};
//
////1.�Ѿ�ʵ����һ�������� �ڴ���һ���µĶ���Ļ� ʵ����������¶�����и�ֵ ����ÿ������캯��
//void test1() {
//	Person p1;
//	Person p2(p1);
//}
////2.��������Ϊ�����������ݵ�ʱ������ֵ����  ʵ�δ����β� ֵ���� Ҳ����ÿ������캯�� ����һ����ʱ���¶���
//void Do_Work(Person p) {
//
//}
//
//void test2() {
//	Person p1;
//	Do_Work(p1);//���ú�����ͬʱ����ֵ���� �൱�ڴ���һ����ʱ�ı���
//}
////3.���ֲ�������Ϊ�����ķ���ֵ�Ļ� Ҳ����ÿ������캯�� ��Ϊ�ڷ��ؾֲ������ͬʱ ������������һ���µ���ʱ������Ϊ
////�����ķ���ֵ ��Ҳ���൱��һ������  ���Ի����
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
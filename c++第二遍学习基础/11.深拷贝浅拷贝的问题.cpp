//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Person1 {
//public:
//	//���캯����ʼ���б�  ע��ð�ŵ�λ��
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
//		cout << "����һ��Ĭ�Ϲ��캯����" << endl;
//	}
//	Person(int age,int height) {
//		m_Age = age;
//		m_Height = new int(height);
//		cout << "����һ���вι��캯����" << endl;
//	}
//	Person(const Person& p) {
//		cout << "����һ������Ŀ������캯��" << endl;
//		this->m_Age = p.m_Age;
//		this->m_Height = new int(*p.m_Height);
//	}
//	~Person() {
//		if (m_Height) {
//			delete m_Height;
//			m_Height = NULL;
//		}
//		cout << "����һ������������" << endl;
//	}
//	int m_Age = 0;
//	int* m_Height = NULL;
//};
////���㲻д�������캯���Ļ� ϵͳ������ṩһ���������캯�� ���и�ֵ����
////������԰����Ǵ���� ��Ϊ������ǳ���������� ����Ǹ�ָ�� �ڶ������ٵ��ڴ� �ú�p2������p1 Ҳ�Ѷ������ٿռ�
////�ĵ�ַ�����˹�ȥ  �ú����������ʱ���� ���ͷŵ�p2  ���ͷŵ�p1 �ͷ�p2��ʱ���Ѿ��ɶ������ڴ��ͷŵ���
////�ͷ�p1��ʱ����ٴ��ͷŶ������ڴ� �γɶ���ͷ� ��һ��������ڴ����ͷ� ���³������ �����ǳ����
//void test1() {
//	Person p1(18,160);
//
//	cout << "p1�����䣺" << p1.m_Age << "p1����ߣ�" << *(p1.m_Height) << endl;
//	Person p2(p1);
//	cout << "p2�����䣺" << p2.m_Age << "p2����ߣ�" << *(p2.m_Height) << endl;
//}
//
////�������������ָ������ ���߶������ٵĿռ�Ļ� һ��Ҫ�Լ�д�������캯�� �������
////���
//void test2() {
//	Person p1(18, 160);
//
//	cout << "p1�����䣺" << p1.m_Age << "p1����ߣ�" << *(p1.m_Height) << endl;
//	Person p2(p1);
//	cout << "p2�����䣺" << p2.m_Age << "p2����ߣ�" << *(p2.m_Height) << endl;
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
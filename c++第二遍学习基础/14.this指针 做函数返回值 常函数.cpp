//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Person {
//public:
//	//���ֵ����ڳ����� �������������޸�������Ա���� �������ǰ��mutable �Ϳ��Ա�ɿ����޸ĵ���
//	void func()const {//const ���ε���thisָ�� ������ �൱��  const Person* const this
//		//m_Age = 20;//���� �����޸�
//		m_B = 100; //�����޸� ��Ϊ��Ա����ǰ��mutable  �����ٳ��������޸���ֵ
//	}
//
//
//	Person(int age):m_Age(age){}
//	Person(const Person& p) :m_Age(p.m_Age) { cout << "����һ���������캯����" << endl; }
//
//	Person& PersonAddAge(const Person& p){ 
//		this->m_Age += p.m_Age;
//		return*this;//thisָ���������ķ���ֵ ���صľ��ǵ�����������Ķ�����  ����������� ��ô�ͻ�ʹ�ÿ������캯��
//		//          �������캯���ĵ���ʱ�� 1.���Ǻ����ķ���ֵ ��Ϊֵ�ķ��� 2.������Ϊ�����Ĳ��� �β� Ҳ����ÿ�������
//		//          �����������ֵ  �ββ������� ��ô�ͻ�������ο������캯�� �β� ����ֵ��һ��=2��
//	}
//	int m_Age = 0;
//	mutable int m_B = 0;
//};
//void test() {
//	Person p1(20);
//	p1.m_B = 20;//�����������ͨ��ʵ����������� ����ͨ����һ�� ����ֻ��������������ٳ�������ʹ���޸�
//	cout << p1.m_B << endl;
//	Person p2 = 20;
//	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
//	cout << "p2�����䣺" << p2.m_Age << endl;
//
//
//	const Person p3(p1);
//	//p3.m_Age = 20;//���� ��Ϊp3�ǳ�����  ��������ʹ�ó�Ա���� ���ǿ���ʹ���������
//	p3.m_B = 100;//�����ǿ��Ե� ��Ϊm_B��һ������ı��� ��������Խ��з���
//	
//	//������ֻ�ܵ��ó�����  ����ʹ�ñ�ĳ�Ա����
//	p3.func();
//	//p3.PersonAddAge(p1);  ����
//}
//
//int main() {
//	test();
//
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////���㴴��һ�����ͬʱ c++ ������Զ��ṩ��������
////Ĭ�Ϲ��캯��
////��������
////�������캯��  ��test����
//class Person {
//public:
//	//�޲ι��캯��
//	Person(){
//		cout << "����һ���޲������캯����" << endl;
//	}
//	//�вι��캯��
//	Person(int age){
//		m_age = age;
//		cout << "����һ���в������캯����" << endl;
//	}
//	Person(string name,int age) {
//		m_age = age;
//		m_Name = name;
//		cout << "����һ���в������캯����" << endl;
//	}
//	//�������캯��
//	//Person(const Person& p) {
//	//	this->m_age = p.m_age;
//	//	cout << "����һ���������캯����" << endl;
//	//}
//	~Person(){
//		cout << "����һ������������" << endl;
//	}
//	int m_age = 0;
//	string m_Name;
//};
//
//void test() {
//	Person p1("����",20);
//	Person p2(p1);//������û�п������캯��  ϵͳ�Զ����� �ú���и�ֵ����
//	cout << p2.m_age << endl;
//	cout << p2.m_Name << endl;
//}
//
//int main() {
//	//1.���ŷ���ʵ��������  �����ڳ����������Զ�������������
//	//Person p1;
//	//Person p2(20);
//	//Person p3(p2);
//
//
//	//2.��ʾ����ʵ�������� ʹ������������е���
//	//Person p1 = Person(10);
//	//Person p3 = Person(p1);
//	//Person(p3);����������д  ��Ϊ��������������Ϊ����һ�������Ķ��� ������p3�൱�� Person p3  ����ʾ�ض���
//	//Person(10);//�൱����������  ʹ����ֱ�ӽ������� ��Ϊ��������û������  �����޷�ʹ�õ��� ϵͳֱ������ ϵͳҲ����ʾ
//	//cout << p3.m_age << endl;
//
//	//3.��ʽת����  ֱ�ӵȺŸ�ֵ �ú�Ⱥ��ұ߾��Ƕ�ʵ�����������Եĸ�ֵ����
//	//Person p4 = 10;
//	//Person p5 = p4;
//	test();
//	return 0;
//}
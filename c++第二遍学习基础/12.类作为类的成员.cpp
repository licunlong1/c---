//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//
//class Phone {
//public:
//	Phone(string name) :m_PName(name) { cout << "����Phone�Ĺ��캯����" << endl; }// �вι��캯��
//	~Phone() {
//		cout << "����Phone������������" << endl;
//	}
//	string m_PName;
//};
//
//class Person {
//	
//
//public:
//	//m_Phone(pname)  ��һ�仰�൱�ڴ�����һ��phoneʵ�������� ��ʽ���õķ�ʽ �൱�� Phone m_Phone = pname
//	Person(string name,string pname):m_Name(name),m_Phone(pname){ cout << "����Person�Ĺ��캯����" << endl; }//�вι��캯��
//	~Person() {
//		cout << "����Person������������" << endl;
//	}
//	string m_Name;
//	Phone m_Phone;
//};
//
//
////����Ϊ����ĳ�Ա��ʱ��  �ȹ������Ա ���챾��  ������˳�����෴�� ���������� ���������Ա 
//void test() {
//	Person p1("����","��Ϊmax");
//
//	cout << p1.m_Name << "����" << p1.m_Phone.m_PName << endl;
//}
//
//
//
//int main() {
//	test();
//	return 0;
//}
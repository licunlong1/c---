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
//	//���������  ��ֵ
//	Person& operator=(const Person& p) {
//		*(this->m_Age) = *(p.m_Age);//��Ҫ�ı�ָ��ĵ�ַ �ı�ָ��ָ���ַ������ �ú󷵻ر���
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
//	//ָ��ά�������������
//	int* m_Age;
//	//�û������
//	int m_Height;
//};
//
////���Ը�ֵ�����
////void test1() {
////	Person p1(18);
////	Person p2(20);
////	Person p3(30);
////	p2 = p1;
////	p2 = p1 = p3;
////	cout << "p1�����䣺" << *(p1.m_Age) << endl;
////	cout << "p2�����䣺" << *(p2.m_Age) << endl;
////	cout << "p3�����䣺" << *(p3.m_Age) << endl;
////
////}
//
////���Թ�ϵ�����
//void test01() {
//	Person p1(18, 160);
//	Person p2(20, 160);
//	Person p3(30, 173);
//	
//
//	cout << "p1�����䣺" << *(p1.m_Age) << "   p1����ߣ�" << (p1.m_Height) << endl;
//	cout << "p2�����䣺" << *(p2.m_Age) << "   p2����ߣ�" << (p2.m_Height) << endl;
//	cout << "p3�����䣺" << *(p3.m_Age) << "   p3����ߣ�" << (p3.m_Height) << endl;
//
//	p3 = p1;
//	if (p3 == p1) {
//		cout << "p1��p3����������ȵ�" << endl;
//	}
//	else {
//		cout << "p1��p3�������ǲ���ȵ�" << endl;
//	}
//	if (p2 != p1) {
//		cout << "p1��p2�������ǲ���ȵ�" << endl;
//	}
//	else {
//		cout << "p1��p3����������ȵ�" << endl;
//	}
//
//}
//
//
////���غ������������
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
////���Ժ������������  ���ֺ����������س�֮Ϊ�º���
//void test02() {
//	My_Printf myprintf1(10);
//	myprintf1(myprintf1(myprintf1("hello bit��"))); //ʹ�������ǳ����� �ǳ������ û�й̶���д��
//	myprintf1(myprintf1(myprintf1("43")));
//
//	My_Printf(1)("1231231");
//	ADD a1(10);
//	a1(a1(30));
//
//	My_Printf myprintf2(10);
//	//�̳а������������ ������ò�Ҫʹ��
//	//if (myprintf1 == myprintf2) cout << "���������" << endl;
//	//if (myprintf1 != myprintf2) cout << "���������" << endl;
//	//�����ǲ���ȷ��  �Ǿ�̬��Ա������������ʵ��������
//	//cout << ADD::m_Num << endl;
//}
//int main() {
//	//test01();
//	test02();
//
//	return 0;
//}
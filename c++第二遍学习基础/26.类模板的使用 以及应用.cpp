//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
//
////��ģ���뺯��ģ���������� �� ��ģ�岻��ʹ���Զ��Ƶ����� ֻ��ʹ��ָ������
////---------------------------------------------------------------------------------
//template<class TypeName,class TypeAge>
//class Person {
//public:
//	//���캯��
//	Person(TypeName name, TypeAge age):m_Name(name),m_Age(age) {
//
//	}
//
//	TypeName m_Name;
//	TypeAge m_Age;
//};
////1.ָ��������������������
//void PrintPerson1(Person<string, int>& p) {
//	cout << "������" << p.m_Name << "\n���䣺" << p.m_Age << endl;
//}
//
////2.��������ʹ��ģ��
//template<typename T1,typename T2>
//void PrintPerson2(Person<T1,T2>&p) {
//	cout << "������" << p.m_Name << "\n���䣺" << p.m_Age << endl;
//	cout << typeid(T1).name() << endl;
//	cout << typeid(T2).name() << endl;
//
//}
//
////3.��������ʹ��ģ��
//template<typename T>
//void PrintPerson3(T& p) {
//	cout << "������" << p.m_Name << "\n���䣺" << p.m_Age << endl;
//	cout << typeid(p).name() << endl;
//
//}
//
//
//void test01() {
//	Person<string,int> p1("�����", 999);
//	PrintPerson1(p1);
//	Person<string, int> p2("��˽�", 999);
//	PrintPerson2(p2);
//	Person<string, int> p3("��ɮ", 999);
//	PrintPerson3(p3);
//
//}
////--------------------------------------------------------------------------------------
//
////��ģ��ĺ�������ʱ��  ��ģ�庯������ʱ���ǵ���ʱ�Ŵ���  û�д�����ʱ����ģ��ĳ�Ա�����ǲ����ڵ�
//class Print1 {
//public:
//	void Print11() {
//		cout << "����person1��ĳ�Ա������" << endl;
//	}
//};
//
//class Print2 {
//public:
//	void Print22() {
//		cout << "����person2��ĳ�Ա������" << endl;
//	}
//};
//
//template<class T>
//class Print3 {
//public:
//	T obj;
//	void func1() {
//		obj.Print11();
//	}
//	void func2() {
//		obj.Print22();
//	}
//
//};
////������ģ���Ա�����ĵ���ʱ�� ����ʱ��  ��Ϊ��ģ���еĳ�Ա���� �ǲ�֪��T��ʲô��������  
////���Ա���׶β����ᴴ��ʵ�������ڵ���ʱ��Żᴴ����Ա����
//void test02() {
//	Print3<Print1> p1;
//	p1.func1();
//	//p1.func2();//��ģ��������Print1���Բ��ɵ���Print2���Ա�ĺ���
//	Print3<Print2> p2;
//	//p2.func1();//��ģ��������Print2���Բ��ɵ���Print1���Ա�ĺ���
//	p2.func2();
//	
//}
//
//int main() {
//	test01();
//
//	test02();
//	return 0;
//}
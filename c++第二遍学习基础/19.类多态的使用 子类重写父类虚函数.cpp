//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Animal {
//public:
//	//�麯�� ����������д �õ�ַ���
//	virtual void func() {
//		cout << "������˵����" << endl;
//	}
//};
//
//class Cat:public Animal {
//public:
//	void func() {
//		cout << "Сè��˵����" << endl;
//	}
//};
//
//class Dog:public Animal {
//public:
//	void func() {
//		cout << "С����˵����" << endl;
//	}
//};
//
////�������ý������������ʵ�ֲ�ͬ�Ķ�����̬  �������ָ��
//void do_Speak(Animal& animal) {
//	animal.func();
//}
//
////��̬ʹ�ó��� 
////1.�����м̳й�ϵ
////2.������д�����麯��
//void test01() {
//	Cat cat;
//	do_Speak(cat);
//
//	Dog dog;
//	do_Speak(dog);
//
//	Animal animal;
//	do_Speak(animal);
//}
//
//
////Э�䷢����Ч��  ����  A��B�Ǽ̳�Ч�� ������Student����д�˸���Person���麯�� �麯���ķ���ֵΪ���ָ��
////�麯���ķ������ͺͼ̳��麯���ķ����������ڼ̳й�ϵ ���ֵĳ�ΪЭ��  
//class A {};
//class B :public A
//{};
//
//class Person
//{
//public:
//	virtual A* BuyTicket()
//	{
//		A a;
//		cout << "ȫ����Ʊ" << endl;
//		return &a;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual B* BuyTicket()
//	{
//		B b;
//		cout << "�����Ʊ" << endl;
//		return &b;
//	}
//};
//
//void Buy_Ticket(Person& p) {
//	p.BuyTicket();
//}
//
////����Э��  Э��Ҳ�ǿ��Է�����̬��  finalֻ���ٸ������ ���߸������Ա������ʹ�� ���Ƹ���ͺ��������̳�
//// override����������ʹ�� �������������������Ա����֮�� �ж��Ƿ���д�麯���ɹ���
//void test02() {
//	Student st;
//	Buy_Ticket(st);
//}
//
//int main() {
//
//	//test01();
//	test02();
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
//
//class Person {
//	//friend Person operator+(const Person& p, const Person& p1);
//	friend ostream& operator<<(ostream& cout,Person p);
//	friend void testAdd();
//public:
//	Person() {}
//	//��ʼ���б�
//	Person(int age,int height):m_Age(age),m_Height(height){}
//	Person(const Person& p):m_Age(p.m_Age), m_Height(p.m_Height)
//	{ cout << "����Person�Ŀ������캯����" << endl; }
//	//���غ���������һ����������  ������
//	Person operator +(const Person& p) {
//		Person temp;
//		temp.m_Age = this->m_Age + p.m_Age;
//		temp.m_Height = this->m_Height + p.m_Height;
//		return temp;
//	}
//	//ǰ��++
//	Person& operator++() {
//		this->m_Age++;
//		this->m_Height++;
//		return *this;
//	}
//	//����++
//	Person operator++(int) {
//		//cout << 1 << endl;
//		Person temp = *this;
//		//cout << 1 << endl;
//		this->m_Age++;
//		this->m_Height++;
//		return temp;
//	}
//private:	 
//
//	int m_Age;
//	int m_Height;
//};
//
//////ȫ�ֺ���������
////Person operator+( const Person&p,const Person& p1) {
////	Person temp;
////	temp.m_Age = p.m_Age + p1.m_Age;
////	temp.m_Height = p.m_Height + p1.m_Height;
////	return temp;
////}
//
////������������  << ���������  ֻ����ȫ�ֺ���������
//ostream& operator<<(ostream& cout,Person p) {
//	cout << "���䣺" << p.m_Age << "   ��ߣ�" << p.m_Height << endl;
//	//cout << p.m_Age;
//	return cout;
//}
////�������������
//void testAdd() {
//	Person p1(10, 50);
//	Person p2(p1);//����Ҳ����ÿ������캯��
//	//cout << p2.m_Age << "   " << p2.m_Height << endl;
//	////���Ա����������+�ŵı���
//	//Person p3 = p1.operator+(p2);
//
//	////ȫ�ֺ���������+�ŵı���
//	//Person p3 = operator+(p1, p2);
//
//	Person p3 = p1 + p2;//����Ҳ����ÿ������캯��
//
//	//cout << p3.m_Age << "   " << p3.m_Height << endl;
//	//cout << p1.m_Age << "   " << p1.m_Height << endl;
//	//������������֮���Ч��  ��ʽ����  ����������������� 
//	//��������ķ���ֵ�ſ���ʽ����  return cout  ���� ostream&
//	cout << p3 << p2 << p1;
//	cout << ++p3;
//	cout << p3++;
//	cout << p3;
//}
//
//int main() {
//	testAdd();
//
//	return 0;
//}
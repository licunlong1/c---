//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Person {
//	//˽�г�Ա�ṩһЩ����Ľӿ�
//public:
//
//	//���ó�Ա������
//	void Set_Name(string name) {
//		m_Name = name;
//	}
//	//���ʳ�Ա������
//	string Get_Name() {
//		return m_Name;
//	}
//	//��������
//	void Set_Age(int age) {
//		if (age < 0 || age>100) {//��������������ݵ���Ч�ԣ�
//			cout << "��������ݲ���ȷ ���������ã�������"<< __LINE__ << endl;
//			m_Age = 0;
//			return;
//		}
//		m_Age = age;
//	}
//	//��ȡ����
//	int Get_Age() {
//		m_Age = 0;
//		return m_Age;
//	}
//	//�������˵�����
//	void Set_Lover(string name) {
//		m_Lover = name;
//	}
//
//private:
//	//����
//	string m_Name;
//	//����
//	int m_Age = 0;
//	//����
//	string m_Lover;
//};
//
//int main() {
//	Person p1;
//	p1.Set_Name("����");
//	cout << "p1��������" << p1.Get_Name() << endl;
//	//ͨ����Ա����  ��Ա����  ��������
//	p1.Set_Lover("С��");
//
//	//����ͨ�����������ú���� ������Ч�� ����0-100֮��
//	p1.Set_Age(111);
//	cout << "p1��������ǣ�" << p1.Get_Age() << endl;
//
//	return 0;
//}
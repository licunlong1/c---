//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Building {
//	//����ȫ�ֺ�������ĺ����� ���Է������ڵ�˽������
//	friend void GoodGay_Visit(Building* building);
//	//����goodgay����Building��ĺ����� ���Է������ڵ�˽������
//	friend class GoodGay;
//	//friend void GoodGay::Visit1();
//public:
//	Building() {
//		m_SetingRoom = "����";
//		m_BedRoom = "����";
//	}
//
//	string m_SetingRoom;
//private:
//	string m_BedRoom;
//};
//
//class GoodGay {
//public:
//
//	void Visit(){
//		cout << "GoodGay �����ڷ��ʺ����ѵģ�" << this->m_Building->m_SetingRoom << endl;
//		//cout << "GoodGay �����ڷ��ʺ����ѵģ�" << this->m_Building->m_BedRoom << endl;
//	}
//	void Visit1();//���еĺ�������
//	GoodGay() {
//		m_Building = new Building;
//	}
//	~GoodGay() {
//		if (m_Building) {
//			delete m_Building;
//			m_Building = NULL;
//		}
//	}
//	Building* m_Building;
//};
//
//
//
//void GoodGay_Visit(Building* building) {
//
//	cout << "�û������ڲιۣ�" << building->m_SetingRoom << endl;
//	cout << "�û������ڲιۣ�" << building->m_BedRoom << endl;
//}
//void GoodGay::Visit1() {
//	cout << "GoodGay ��ĳ�Ա�������ڷ��ʺ����ѵģ�" << m_Building->m_SetingRoom << endl;
//	cout << "GoodGay ��ĳ�Ա�������ڷ��ʺ����ѵģ�" << m_Building->m_BedRoom << endl;
//}
//
//
////ǰ��������ȱ��   ������Էֿ��ļ�.h .cppд��ͬ���� �ú�ͷ�ļ������������ a����b�� b����a�� ��Ҫ�ֿ�ͷ�ļ�
//class b;
//class a {
//	b* B;
//public:
//	a();
//};
//
//class b {
//public:
//	b() { A = "woss"; }
//	string A;
//};
////����֮�󲻿�������ȥʹ��b�� ��Ϊ������ֻ��֪����������� ����b�����Ĵ�С����� ֻ��ʹ��ָ������λ��
//a::a() {
//	B = new b;
//	cout << "����a�Ĺ��캯����" << B->A << endl;
//}
//void test() {
//	a a1;
//}
//
//
//int main() {
//	Building building;
//	GoodGay_Visit(&building);
//
//	GoodGay good;
//	good.Visit();
//	good.Visit1();
//	//test();
//	return 0;
//}
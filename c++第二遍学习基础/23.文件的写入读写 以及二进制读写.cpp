//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
////���ļ�  д��
//void test01() {
//
//	//����ͷ�ļ�
//	
//	//����������ļ�����
//	ofstream ofs;
//	//���ļ�             д��ķ�ʽ��
//	ofs.open("test.txt", ios::out);
//	//д���ļ�
//	ofs << "���� ����" << endl << "���䣺18" << endl;
//	//�ر��ļ�
//	ofs.close();
//}
//
////���ļ�  ��ȡ
//void test02() {
//
//	//����ͷ�ļ�
//
//	//����������ļ�����
//	ifstream ifs;
//	//���ļ�             д��ķ�ʽ��
//	ifs.open("test.txt", ios::in);
//
//	//�ж��ļ��Ƿ�򿪳ɹ�
//	if (!ifs.is_open()) {
//		cout << "file open fail!" << endl;
//		ifs.close();
//		return;
//	}
//	char Buf[1024];
//	//��ȡ�ļ�
//	
//	//1.ֱ�Ӷ�ȡ
//	//while (ifs >> Buf) {
//	//	cout << Buf << endl;
//	//}
//	//��ʱ�� Buf�������治�����κ����� �����ȡÿ��ѭ�������������� ���ļ�ָ��λ�ÿ�ʼ��ȡ
//	//cout << Buf << endl;
//	
//	//2.�ļ�����ķ��� getline  getline��ȡһ������ ���ǲ����ȡ�ļ��еĻ���
//	//while (ifs.getline(Buf, sizeof(Buf))) {
//	//	cout << Buf << endl;
//	//}
//	
//	//3.ȫ�ֵķ��� getline ���һ�������ȡһ���еĻ���  �������һ��string���͵��ַ��� 
//	string Buf1;
//	while (getline(ifs, Buf1)) {
//		cout << Buf1 << endl;
//	}
//
//
//	//�ر��ļ�
//	ifs.close();
//}
//class Person {
//
//public:
//	char m_Name[64];
//	int m_Age;
//};
//
//
////�������ļ�д��
//void test03() {
//	Person p = { "�Ʋ�",109 };
//	//�����ļ�������
//	ofstream ofs;
//	//���ļ�
//	ofs.open("test1.txt", ios::out | ios::binary);
//	//д������
//	ofs.write((const char*)&p, sizeof(p));
//
//	//�ر��ļ�
//	ofs.close();
//}
////�������ļ���ȡ
//void test04() {
//	Person p1;
//	//�����ļ�������
//	ifstream ifs;
//	//���ļ�
//	ifs.open("test1.txt", ios::in | ios::binary);
//	if (!ifs.is_open()) {
//		cout << "file open fail��" << endl;
//		ifs.close();
//		return;
//	}
//	//д������
//	ifs.read((char*)&p1, sizeof(p1));
//	//ifs.read((const char*)&a, sizeof(a));
//	cout << "������"<<p1.m_Name<<"\n���䣺"<<p1.m_Age << endl;
//	//�ر��ļ�
//	ifs.close();
//}
//int main() {
//	//д�ļ�
//	//test01();
//
//	//���ļ�
//	//test02();
//
//	//������д���ļ�
//	test03();
//
//	//�����ƶ�ȡ�ļ�
//	test04();
//	return 0;
//}
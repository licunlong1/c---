//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
////����ģ������ͨȫ�ֺ���������
////1.��ͨ�������Է�����ʽ����ת��  ��������֮���
////2.����ģ�������ָ�����͵Ļ������Է�����ʽ����ת��
////3.����ģ�����ָ�����͵Ļ�  ���Ȳ����ǲ�ͬ����  �ǿ��Է�����ʽ����ת���� 
//
//
//int Calculate_Add(int a,int b) {
//	cout << "����һ��Calculate_Add�����ĵ��ã�" << endl;
//	return a + b;
//}
//
//template<typename T>
//T Calculate_Add(T a,T b) {
//	cout << "����һ��Calculate_Add����ģ��ĵ��ã�" << endl;
//	cout << a << b << endl;
//	return a + b;
//}
//
//template<typename T>
//T Calculate_Add(T& a, T& b,T&c) {
//	cout << "����һ��Calculate_Add��������ģ��ĵ��ã�" << endl;
//
//	return a + b + c;
//}
////���Ժ�����ģ�庯���ĵ��ù���   �����д��ģ�庯��  �Ͳ�Ҫдȫ�ֺ���  ��ͨ������ ��ֹ�����Եĳ��֣�
//void test01() {
//	int a = 10, b = 20, c = 100;
//	////1.������ģ������ͨȫ�ֺ�������һ��ʱ  ���ȵ�����ͨ����
//	//cout << "a + b = " << Calculate_Add(a, b) << endl;
//	////2.������ʹ�ÿ�ģ�����͵�ʱ�� ָ��ģ��Ϊ������ ����ģ�庯��
//	//cout << "a + b = " << Calculate_Add<>(a, b) << endl;
//	////3.ģ�庯��Ҳ���Է�������
//	//cout << Calculate_Add<int>(a, b, c) << endl;
//	//4.ģ�庯���и��õ�ƥ���� ����ģ�庯��
//
//	char c1 = 'A', c2 = 'b';
//	int ret = Calculate_Add(a, c2);//������õ�ʱ��ᷢ����������  ��Ϊchar�ֽ�Ϊ1  С��int�ֽ� ��ͨ����
//	int ret1 = Calculate_Add(c1, c2);
//	cout << "a+c2=" << ret << endl;
//	cout << "c1+c2=" << ret1 << endl;
//	cout << Calculate_Add<int>(b, c2) << endl;
//
//	ret = a + c2;
//	ret1 = c1 + c2;
//	cout << "a+c2=" << ret << endl;
//	cout << "c1+c2=" << ret1 << endl;
//}
//
//
////����ģ��ľ����� ����ģ����������ͨ���� ������Զ������͵Ļ� ����ģ��ʵ�ֲ�����  ���о�����
////����һ����
//class Person {
//
//public:
//	string m_Name;
//	int m_Age;
//};
//
////�Ƚ��Ƿ���ȵĺ���ģ��
//template<typename T>
//bool T_Compare(T& a, T& b) {
//	return a == b;
//}
//
////ģ�庯��������
//template<> bool T_Compare(Person& p1, Person& p2) {
//	//���ֶ��ǿ��Ե�һ���Ƿ���  �ַ����ķ���  ��һ�����ַ���string�����������
//	//if (p1.m_Name.compare(p2.m_Name) == 0 && p1.m_Age == p2.m_Age) {
//	//	return true;
//	//}
//	//else {
//	//	return false;
//	//}
//	if (p1.m_Name == (p2.m_Name) && p1.m_Age == p2.m_Age) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
////����ģ�庯���ľ�����
//void test02() {
//	Person p1 = { "����",20 };
//	Person p2 = { "����1",20 };
//
//	if (T_Compare(p1, p2)) {
//		cout << "p1��p2����ȵģ�" << endl;
//	}
//	else {
//		cout << "p1��p2�ǲ���ȵģ�" << endl;
//	}
//}
//
//int main() {
//
//	//test01();
//
//	test02();
//
//
//	return 0;
//}
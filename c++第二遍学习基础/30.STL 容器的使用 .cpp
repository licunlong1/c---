//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<deque>//˫������ ����ͷ��ɾ β��ɾ �����ٶȱ�vertor�� �����ٶȱȽ���
//#include<vector>//�������� ͷ��Ч�ʱȽϵ�  β��ɾ �����ٶ�ͦ��
//#include<list>//�ڲ���˫������
//#include<algorithm>//��׼�㷨
//#include<map>//��ֵ�Ե���ʽ  heapmap��
//#include<stack>//ջ�����ݽṹ  first int last out   filo  ȡջ��top  ɾ��ջ������pop push
//#include<set>//���� �����в�������ͬ��Ԫ�� multiset��������ͬ��Ԫ��
//#include<queue>//���� �Ƚ��ȳ�  first int first out fifo ȡ��ͷ��β front back  push pop
//using namespace std;
//
////STL  stand template library  ��׼ģ���
////STL ���������  ���� �㷨 ������ �º��� ������ ����������
////1.����ʽ����  �������������洢��һ��ռ�  ���� vector deque stack queue
////2.������������ �����ϲ��������洢�� �߼��������Կռ䣨����Ҳ�����ԣ� list map set ��multi��
////1.�ʱ��㷨  ʵ��������Ǹı����������ݳ�Ϊ�ʱ��㷨  ���� copy replace pop
////2.���ʱ��㷨 ʵ��������ǲ��ı����������ݳ�Ϊ���ʱ��㷨  ����find find_if for_each
////�������õıȽ϶��  ˫������� ���������
//
//
//
//
////������
//class Person {
//public:
//	Person(string name, int age) :m_Name(name), m_Age(age) {
//
//	}
//
//	string m_Name;
//	int m_Age;
//
//};
////��ӡ�����Եĺ���
//void PrintPerson(vector<Person> p) {
//	//�Զ������Ƶ�����
//	for (auto p1 : p) {
//		cout <<"������"<< p1.m_Name <<"\n���䣺"<< p1.m_Age << endl;
//	}
//}
////��ӡ�����Եĺ���  ������
//void PrintPerson1(vector<Person> p) {
//	//����������
//	for (vector<Person>::iterator it = p.begin(); it != p.end(); it++) {
//		cout << "������" << it->m_Name << "\n���䣺" << it->m_Age << endl;
//
//	}
//}
////����vector��������������
//void test01() {
//	vector<Person> v1;
//	Person p1("��˽�", 999);
//	Person p2("����", 999);
//	Person p3("�����", 999);
//	Person p4("��ʴ��", 999);
//	Person p5("С����", 999);
//
//	v1.push_back(p1);
//	v1.push_back(p2);
//	v1.push_back(p3);
//	v1.push_back(p4);
//	v1.push_back(p5);
//	PrintPerson(v1);
//	//PrintPerson1(v1);
//
//}
//
//
////��������Ƕ������
//void test02() {
//	vector<vector<int>> v;
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> v3;
//	vector<int> v4;
//
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//		v2.push_back(i + 1);
//		v3.push_back(i + 2);
//		v4.push_back(i + 3);
//	}
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//
//	for (auto i : v) {
//		for (auto j : i) {
//			cout << j << " ";
//		}
//		cout << endl;
//	}
//}
//
////����string����
//void test03() {
//	string str1;
//	str1 = "abcdefghde";
//	cout << str1 << endl;
//	str1 += str1;
//	cout << str1 << endl;
//	string str2;
//
//	str2.assign(10, 'w');
//	cout << str2 << endl;
//
//	string str3(str2);
//	cout << str3 << endl;
//	string str4;
//	str4.assign(str2.begin(), str2.end());
//	cout << str4 << endl;
//
//	int pos = str1.find("de");
//	cout << pos << endl;
//	int pos1 = str1.rfind("de");
//	cout << pos1 << endl;
//
//
//	str4.replace(str4.begin() + 1, str4.begin() + 4, "abcedf");
//	cout << str4 << endl;
//
//	str4[str4.rfind('w')] = 'a';
//	cout << str4 << endl;
//	for (string::reverse_iterator it = str4.rbegin(); it != str4.rend(); it++) {
//		cout << *it << endl;
//		
//	}
//	for (size_t i = 0; i < str4.size(); i++) {
//		cout << str4.at(i) << " ";
//	}
//
//	cout << str1.substr(4) << endl;
//}
//
////vector�Ĳ���  front back������Ҳ�ǿ���ȡ������  v.at(i)   swap ���Խ�������vector
//void test04() {
//
//	vector<int> v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i + 10);
//	}
//	if (!v.empty()) {
//		cout << "v��Ϊ��" << endl;
//		cout << "v������Ϊ��" << v.capacity() << endl;
//		cout << "v�Ĵ�СΪ��" << v.size() << endl;
//	}
//
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//
//	v.push_back(1);
//	cout << "v������Ϊ��" << v.capacity() << endl;
//	cout << "v�Ĵ�СΪ��" << v.size() << endl;
//
//	//����v2�����洢��10������� ���ٿռ俪���˶��ٴ�
//	vector<int> v2;
//	vector<int> v3;
//	v3.reserve(100000);
//	int count = 0;
//	int* p = NULL;
//	for (int i = 0; i < 100000; i++) {
//		v2.push_back(i);
//		if (p != &v2[0]) {
//			count++;
//			p = &v2[0];
//		}
//	}
//	cout << "v2�����洢��10������� ������" << count << "���ڴ棡" << endl;
//
//	count = 0;
//	for (int i = 0; i < 100000; i++) {
//		v3.push_back(i);
//		if (p != &v3[0]) {
//			count++;
//			p = &v3[0];
//		}
//	}
//	cout << "v3�����洢��10������� ������" << count << "���ڴ棡" << endl;
//
//
//	v3.resize(10);
//	cout << "v3������Ϊ��" << v3.capacity() << endl;
//	cout << "v3�Ĵ�СΪ��" << v3.size() << endl;
//	vector<int>(v3).swap(v3);
//	cout << "\nv3������Ϊ��" << v3.capacity() << endl;
//	cout << "v3�Ĵ�СΪ��" << v3.size() << endl;
//
//	v3.resize(20, 100);
//	for (auto i : v3) cout << i << " ";
//}
//
////deque��vectorӦ�õķ�������һ��  deque����һ��ͷ��ͷɾ Ч�ʱȽϸ� ͷβָ��ά����
////deque��û�������ĸ��� ����һ������һ�� ������������
//bool compare(int val) {
//	return val < 9;
//}
//
//void my_print(int val) {
//	cout << val << " ";
//}
//void test05() {
//
//	deque<int> d1;
//	int count = 0;
//	int* p = NULL;
//	for (int i = 0; i < 20; i++) {
//		d1.push_front(i);
//		if (p != &d1[0]) {
//			count++;
//			p = &d1[0];
//		}
//	}
//	//ͷ�� �������20  ����ѭ����������� ˵�����ٿռ俪����N�� ����ͷ��ȷʵ�ܷ���
//	cout << count << endl;
//
//	for (int i = 0; i < 20; i++)cout << d1.at(i) << " ";
//	cout << endl;
//
//	d1.insert(find(d1.begin(), d1.end(), 9), 10);
//	for (int i = 0; i < 21; i++)cout << d1.at(i) << " ";
//	cout << endl;
//
//	//find_if��Ҫ�Լ��ֶ�д��ν�� Ҳ���Ǻ�����ָ�� compare
//	deque<int>::iterator it = find_if(d1.begin(), d1.end(), compare);
//	for_each(it, d1.end(), my_print);
//}
//
//int main() {
//	//test01();
//
//	//test02();
//
//	//test03();
//
//	//test04();
//
//	test05();
//	return 0;
//}
////#include<vector>
////#include<iostream>
////#include<memory>
////using namespace std;
//////�۲���
////class Observer
////{
////public:
////	Observer(void  (*doA)()) :doAction(doA) {}
////	void (*doAction)();//����ָ��
////};
////
//////���۲�����
////class Subject
////{
////	vector<Observer> observers;
////public:
////	void attach(Observer observer)
////	{
////		observers.push_back(observer);
////	}
////	void notifyAllObservers()
////	{
////		for (auto it = observers.begin(); it != observers.end(); it++)
////		{
////			it->doAction();
////		}
////	}
////};
////
////int main()
////{
////	Subject sj;
////	sj.attach(Observer([] {static int state = 0; state++; cout << "������1��ǰ״̬Ϊ" << state << endl; }));//��������
////	sj.attach(Observer([] {static int state = 2; state++; cout << "������2��ǰ״̬Ϊ" << state << endl; }));
////	sj.notifyAllObservers();
////}

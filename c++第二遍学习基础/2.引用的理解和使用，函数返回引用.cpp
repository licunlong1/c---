//#include<iostream>
//using namespace std;
//
//int& test1() {
//	static int a = 20;
//	return a;
//}
//
//
//int main() {
//
//	int& ref = test1();
//	cout << ref << endl;
//	cout << ref << endl;
//
//	test1() = 200;//���ؾ�̬�������õĺ���������Ϊ��ֵ�޸� �亯������ֵ���Ǿ�̬���������� �ú����̬������ֵ
//
//	cout << ref << endl;
//
//	int a = 1000;
//	int b = 2000;
//	int& ref1 = a;//���õı��ʾ���һ��ָ�볣�� int &ref1 = int * const ref1 ָ���ָ�򲻿��Ըı䣬ָ���ֵ����
//	              //int const * ref1���Ƕ�ref1��ȡ*���������ã�Ҳ����ָ��ָ�������ֵ���ɸı䣬ָ���ָ��ɸı�
//	ref1 = b;//����ֻ�ǰ�b��ֵ����ref1 ref1������b�����ã�����һ�д���ܺõ�˵���� ref1��a������
//	ref1 = 20000;
//	cout << ref1 << endl;
//	cout << a << "\n" << b << endl;
//	return 0;
//}
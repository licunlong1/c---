//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//template<typename T>
//void My_Swap(T& a, T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//template<typename T>
//void func() {
//	cout << "����ģ��func�ĵ���" << endl;
//}
//
////ģ��ʵ�ֵ����� ð������
//template<typename T>
//void T_Sort(T* arr, int len) {
//	for (int i = 0; i < len - 1; i++) {
//		for (int j = 0; j < len - 1 - i; j++) {
//			if (arr[j] > arr[j + 1]) {
//				My_Swap<T>(arr[j], arr[j + 1]);
//			}
//		}
//	}
//}
////ģ��ʵ�ֵĴ�ӡ���麯��
//template<typename T>
//void T_Print(T*arr,int len) {
//	for (int i = 0; i < len; i++) {
//		cout << arr[i];
//	}
//	cout << endl;
//}
//
////����ģ���ʹ�� ��������
//void test01() {
//	int a = 12, b = 13;
//	//1.�����Ƶ�ʽ
//	My_Swap(a, b);
//	cout << "a= " << a << "\nb=" << b << endl;
//	double c = 1.2, d = 1.3;
//	//2.ָ������
//	My_Swap<double>(c, d);
//	cout << "c= " << c << "\nd=" << d << endl;
//}
////����ģ����������� ����Ϊchar  int
//void test02() {
//	char str[] = "hgfedcba";
//	T_Sort(str, strlen(str));
//	T_Print(str, strlen(str));
//	int arr[] = { 2,3,5,1,7,9,8,6,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	T_Sort(arr, sz);
//	T_Print(arr, sz);
//
//}
//
//int main() {
//	
//	//test01();
//	
//	test02();
//
//	//func();  ������д�Ǵ���� ��Ϊģ����Ҫָ�����ͻ����Ƶ����� �����������û�������޷��Ƶ� ֻ��ָ������
//	func<int>();
//	return 0;
//}
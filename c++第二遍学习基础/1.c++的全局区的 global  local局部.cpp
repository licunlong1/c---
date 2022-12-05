//#include<iostream>
//using namespace std;
//
//int g_a = 10;
//int g_b = 20;
//
//static int s_g_a = 10;
//
//const int c_g_a = 20;
//int main() {
//
//	int a = 10;
//	int b = 20;
//	cout << "局部变量a的地址是：" << (int)&a << endl;
//	cout << "局部变量b的地址是：" << (int)&b << endl;
//
//	static int s_a = 10;
//	static int s_b = 20;
//	cout << "静态局部变量s_a的地址是：" << (int)&s_a << endl;
//	cout << "静态局部变量是s_b的地址是：" << (int)&s_b << endl;
//
//	const int c_a = 20;
//	cout << "const修饰的局部变量c_a的地址是：" << (int)&c_a << endl;
//
//	cout << "全局变量g_a的地址是：" << (int)&g_a << endl;
//	cout << "静态修饰的全局变量s_g_a的地址是：" << (int)&s_g_a << endl;
//	cout << "const修饰的全局变量c_g_a的地址是：" << (int)&c_g_a << endl;
//	cout << "字符串常量的地址是：" << (int)&"hello" << endl;
//
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<iostream>
//using namespace std;
////函数模板与普通全局函数的区别
////1.普通函数可以发生隐式类型转换  整形提升之类的
////2.函数模板如果不指定类型的话不可以发生隐式类型转换
////3.函数模板如果指定类型的话  首先参数是不同类型  是可以发生隐式类型转换的 
//
//
//int Calculate_Add(int a,int b) {
//	cout << "这是一个Calculate_Add函数的调用！" << endl;
//	return a + b;
//}
//
//template<typename T>
//T Calculate_Add(T a,T b) {
//	cout << "这是一个Calculate_Add函数模板的调用！" << endl;
//	cout << a << b << endl;
//	return a + b;
//}
//
//template<typename T>
//T Calculate_Add(T& a, T& b,T&c) {
//	cout << "这是一个Calculate_Add函数重载模板的调用！" << endl;
//
//	return a + b + c;
//}
////测试函数和模板函数的调用规则   （如果写了模板函数  就不要写全局函数  普通函数了 防止二义性的出现）
//void test01() {
//	int a = 10, b = 20, c = 100;
//	////1.当函数模板与普通全局函数名称一致时  优先调用普通函数
//	//cout << "a + b = " << Calculate_Add(a, b) << endl;
//	////2.当函数使用空模板类型的时候 指定模板为空类型 调用模板函数
//	//cout << "a + b = " << Calculate_Add<>(a, b) << endl;
//	////3.模板函数也可以发生重载
//	//cout << Calculate_Add<int>(a, b, c) << endl;
//	//4.模板函数有更好的匹配性 调用模板函数
//
//	char c1 = 'A', c2 = 'b';
//	int ret = Calculate_Add(a, c2);//这里调用的时候会发生整形提升  因为char字节为1  小于int字节 普通函数
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
////函数模板的局限性 函数模板试用于普通类型 如果是自定义类型的话 函数模板实现不出来  会有局限性
////创建一个类
//class Person {
//
//public:
//	string m_Name;
//	int m_Age;
//};
//
////比较是否相等的函数模板
//template<typename T>
//bool T_Compare(T& a, T& b) {
//	return a == b;
//}
//
////模板函数的重载
//template<> bool T_Compare(Person& p1, Person& p2) {
//	//两种都是可以的一种是方法  字符串的方法  另一种是字符串string运算符的重载
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
////测试模板函数的局限性
//void test02() {
//	Person p1 = { "张三",20 };
//	Person p2 = { "张三1",20 };
//
//	if (T_Compare(p1, p2)) {
//		cout << "p1和p2是相等的！" << endl;
//	}
//	else {
//		cout << "p1和p2是不相等的！" << endl;
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
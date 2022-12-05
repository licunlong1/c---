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
//	test1() = 200;//返回静态变量引用的函数可以作为左值修改 其函数的左值就是静态变量的引用 让后给静态变量赋值
//
//	cout << ref << endl;
//
//	int a = 1000;
//	int b = 2000;
//	int& ref1 = a;//引用的本质就是一个指针常量 int &ref1 = int * const ref1 指针的指向不可以改变，指针的值可以
//	              //int const * ref1就是对ref1的取*操作不可用，也就是指针指向变量的值不可改变，指针的指向可改变
//	ref1 = b;//这里只是把b的值给了ref1 ref1并不是b的引用，下面一行代码很好的说明了 ref1是a的引用
//	ref1 = 20000;
//	cout << ref1 << endl;
//	cout << a << "\n" << b << endl;
//	return 0;
//}
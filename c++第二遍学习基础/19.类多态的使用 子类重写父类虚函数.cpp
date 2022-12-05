//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Animal {
//public:
//	//虚函数 在子类中重写 让地址晚绑定
//	virtual void func() {
//		cout << "动物在说话！" << endl;
//	}
//};
//
//class Cat:public Animal {
//public:
//	void func() {
//		cout << "小猫在说话！" << endl;
//	}
//};
//
//class Dog:public Animal {
//public:
//	void func() {
//		cout << "小狗在说话！" << endl;
//	}
//};
//
////父类引用接受子类对象来实现不同的多种形态  父类对象指针
//void do_Speak(Animal& animal) {
//	animal.func();
//}
//
////多态使用场景 
////1.必须有继承关系
////2.子类重写父类虚函数
//void test01() {
//	Cat cat;
//	do_Speak(cat);
//
//	Dog dog;
//	do_Speak(dog);
//
//	Animal animal;
//	do_Speak(animal);
//}
//
//
////协变发生的效果  类型  A和B是继承效果 而子类Student中重写了父类Person的虚函数 虚函数的返回值为类的指针
////虚函数的返回类型和继承虚函数的返回类型属于继承关系 这种的成为协变  
//class A {};
//class B :public A
//{};
//
//class Person
//{
//public:
//	virtual A* BuyTicket()
//	{
//		A a;
//		cout << "全价买票" << endl;
//		return &a;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual B* BuyTicket()
//	{
//		B b;
//		cout << "半价买票" << endl;
//		return &b;
//	}
//};
//
//void Buy_Ticket(Person& p) {
//	p.BuyTicket();
//}
//
////测试协变  协变也是可以发生多态的  final只能再父类类后 或者父类类成员函数后使用 限制该类和函数不被继承
//// override是在子类中使用 在子类类后或者子类类成员函数之后 判断是否重写虚函数成功！
//void test02() {
//	Student st;
//	Buy_Ticket(st);
//}
//
//int main() {
//
//	//test01();
//	test02();
//	return 0;
//}
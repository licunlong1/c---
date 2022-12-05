//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//
//class AbstractDrinking {
//public:
//	void Boil_Witer(){
//		cout << "开始煮水！" << endl;
//	}
//	virtual void Stock()  = 0;
//	void Up_Glass() {
//		cout << "倒入杯中！" << endl;
//	}
//	virtual void AddCondiment() = 0;
//};
//void Do_Drink1(AbstractDrinking& b);
//class Coffee :public AbstractDrinking {
//public:
//	virtual void Stock() {
//		cout << "加入咖啡！" << endl;
//	}
//	void operator()(Coffee* abc) {
//		Do_Drink1(*abc);
//		delete abc;
//	}
//	virtual void AddCondiment() {
//		cout << "加入糖和牛奶！" << endl;
//	}
//};
//class Tea :public AbstractDrinking {
//public:
//	virtual void Stock() {
//		cout << "加入龙井茶！" << endl;
//	}
//	virtual void AddCondiment() {
//		cout << "加入柠檬！" << endl;
//	}
//};
////使用父类的引用接受子类的对象来实现多态
//void Do_Drink1(AbstractDrinking& b) {
//	b.Boil_Witer();
//	b.Stock();
//	b.Up_Glass();
//	b.AddCondiment();
//}
////使用父类的指针来使用多态 使用完即可删除 释放 防止内存泄露
//void Do_Drink2(AbstractDrinking* b) {
//	b->Boil_Witer();
//	b->Stock();
//	b->Up_Glass();
//	b->AddCondiment();
//	delete b;
//}
//void test01() {
//	AbstractDrinking* b = new Coffee;
//	Do_Drink1(*b);
//	delete b;
//	cout << "----------------------" << endl;
//	b = new Tea;
//	Do_Drink1(*b);
//	delete b;
//}
//void test02() {
//	Do_Drink2(new Coffee);
//	cout << "----------------------" << endl;
//	Do_Drink2(new Tea);
//}
////使用仿函数进行调用  不太适应
//void test03() {
//	Coffee* c = new Coffee;
//	Coffee()(c);
//}
//
//void test04(int*& a) {
//	cout << *a << endl;
//}
//int main() { 
//
//	//test01();
//
//	test02();
//
//	//test03();
//
//	//int* a = new int(10);
//	//test04(a);//这样传递的话是可以传递指针的引用 函数形参可以用指针引用来接收
//
//	test04(new int(10));//这样 是不可以的  因为 堆区创建了但是并没有拿变量接收 所以不可指针引用接收
//
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Building {
//	//声明全局函数是类的好朋友 可以访问类内的私有属性
//	friend void GoodGay_Visit(Building* building);
//	//声明goodgay类是Building类的好朋友 可以访问类内的私有属性
//	friend class GoodGay;
//	//friend void GoodGay::Visit1();
//public:
//	Building() {
//		m_SetingRoom = "客厅";
//		m_BedRoom = "卧室";
//	}
//
//	string m_SetingRoom;
//private:
//	string m_BedRoom;
//};
//
//class GoodGay {
//public:
//
//	void Visit(){
//		cout << "GoodGay 类正在访问好朋友的：" << this->m_Building->m_SetingRoom << endl;
//		//cout << "GoodGay 类正在访问好朋友的：" << this->m_Building->m_BedRoom << endl;
//	}
//	void Visit1();//类中的函数声明
//	GoodGay() {
//		m_Building = new Building;
//	}
//	~GoodGay() {
//		if (m_Building) {
//			delete m_Building;
//			m_Building = NULL;
//		}
//	}
//	Building* m_Building;
//};
//
//
//
//void GoodGay_Visit(Building* building) {
//
//	cout << "好基友正在参观：" << building->m_SetingRoom << endl;
//	cout << "好基友正在参观：" << building->m_BedRoom << endl;
//}
//void GoodGay::Visit1() {
//	cout << "GoodGay 类的成员函数正在访问好朋友的：" << m_Building->m_SetingRoom << endl;
//	cout << "GoodGay 类的成员函数正在访问好朋友的：" << m_Building->m_BedRoom << endl;
//}
//
//
////前置声明的缺陷   这里可以分开文件.h .cpp写不同的类 让后头文件中声明别的类 a包含b类 b包含a类 需要分开头文件
//class b;
//class a {
//	b* B;
//public:
//	a();
//};
//
//class b {
//public:
//	b() { A = "woss"; }
//	string A;
//};
////声明之后不可再类中去使用b类 因为声明了只是知道有这个类了 但是b类具体的大小不清楚 只能使用指针留出位置
//a::a() {
//	B = new b;
//	cout << "这是a的构造函数：" << B->A << endl;
//}
//void test() {
//	a a1;
//}
//
//
//int main() {
//	Building building;
//	GoodGay_Visit(&building);
//
//	GoodGay good;
//	good.Visit();
//	good.Visit1();
//	//test();
//	return 0;
//}
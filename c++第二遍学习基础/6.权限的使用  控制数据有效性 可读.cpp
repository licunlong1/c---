//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Person {
//	//私有成员提供一些对外的接口
//public:
//
//	//设置成员的名字
//	void Set_Name(string name) {
//		m_Name = name;
//	}
//	//访问成员的名字
//	string Get_Name() {
//		return m_Name;
//	}
//	//设置年龄
//	void Set_Age(int age) {
//		if (age < 0 || age>100) {//检测设置年龄数据的有效性！
//			cout << "输入的数据不正确 请重新设置！行数："<< __LINE__ << endl;
//			m_Age = 0;
//			return;
//		}
//		m_Age = age;
//	}
//	//获取年龄
//	int Get_Age() {
//		m_Age = 0;
//		return m_Age;
//	}
//	//设置情人的名字
//	void Set_Lover(string name) {
//		m_Lover = name;
//	}
//
//private:
//	//姓名
//	string m_Name;
//	//年龄
//	int m_Age = 0;
//	//情人
//	string m_Lover;
//};
//
//int main() {
//	Person p1;
//	p1.Set_Name("张三");
//	cout << "p1的姓名：" << p1.Get_Name() << endl;
//	//通过成员函数  成员方法  设置名字
//	p1.Set_Lover("小三");
//
//	//可以通过设置年龄让后进行 数据有效性 年龄0-100之间
//	p1.Set_Age(111);
//	cout << "p1的年龄该是：" << p1.Get_Age() << endl;
//
//	return 0;
//}
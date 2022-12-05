//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
////public权限 在类内是可以访问的 在类外可以访问         公共权限
////protected权限 在类内是可以访问的 在类外不可以访问    保护权限
////private权限 在类内是可以访问的 在类外不可以访问      私有权限
//
////创建一个类
//class Person {
//public:
//	string m_Name;
//protected:
//	string m_Car;
//private:
//	string m_Password;
//public://对外的一些接口  但是不能访问内部protected和private下的内容  对私有权限和保护权限不可访问
//	void func() {
//		m_Name = "李四";
//		m_Car = "拖拉机";
//		m_Password = "123456";
//	}
//	void ShowInfo() {
//		cout << "姓名：" << this->m_Name << "  车型：" << this->m_Car << "  银行卡密码：" << this->m_Password << endl;
//	}
//
//};
//typedef Person P;
//
//int main() {
//	//实例化对象 实例化出一个人
//	P p1;
//	p1.func();
//	p1.ShowInfo();
//	//类外实例化对象 不可以访问类内的保护和私有权限
//	//p1.m_Password = "123123123";
//	//p1.m_Car = "兰博基尼";
//
//	vector<int> a;
//	return 0;
//}
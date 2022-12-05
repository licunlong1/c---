//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
////创建一个学生类
//class Student {
//public:
//	//类中的属性和行为 统一成为成员
//	//属性  成员属性  成员变量
//	//行为  成员函数  成员方法
// 
//	//属性
//	//学生的姓名和学号
//	string st_name;
//	int st_id = 0;
//
////protected:
//	//行为 
//	//设置学生的姓名
//	void Set_StName(string name) {
//		this->st_name = name;
//	}
//	//设置学生的id
//	void Set_Stid(int id) {
//		this->st_id = id;
//	}
//	//打印学生的信息
//	void print() {
//		cout << "该学生的姓名：" << this->st_name << endl;
//		cout << "该学生的id：" << this->st_id << endl;
//	}
//};
//
//
//int main() {
//	//实例化对象 s1
//	Student s1;
//	string name;
//	int id;
//	cout << "请输入学生的姓名：";
//	cin >> name;
//	cout << "请输入学生的id：";
//	cin >> id;
//	s1.Set_StName(name);
//	s1.Set_Stid(id);
//	s1.print();
//
//	return 0;
//}
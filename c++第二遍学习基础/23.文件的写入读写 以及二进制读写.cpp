//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
////打开文件  写入
//void test01() {
//
//	//引入头文件
//	
//	//创建输出流文件对象
//	ofstream ofs;
//	//打开文件             写入的方式打开
//	ofs.open("test.txt", ios::out);
//	//写入文件
//	ofs << "张三 老六" << endl << "年龄：18" << endl;
//	//关闭文件
//	ofs.close();
//}
//
////打开文件  读取
//void test02() {
//
//	//引入头文件
//
//	//创建输出流文件对象
//	ifstream ifs;
//	//打开文件             写入的方式打开
//	ifs.open("test.txt", ios::in);
//
//	//判断文件是否打开成功
//	if (!ifs.is_open()) {
//		cout << "file open fail!" << endl;
//		ifs.close();
//		return;
//	}
//	char Buf[1024];
//	//读取文件
//	
//	//1.直接读取
//	//while (ifs >> Buf) {
//	//	cout << Buf << endl;
//	//}
//	//这时候 Buf数组里面不会有任何数据 这个读取每次循环都会把数据清楚 从文件指针位置开始读取
//	//cout << Buf << endl;
//	
//	//2.文件对象的方法 getline  getline读取一行数据 但是不会读取文件中的换行
//	//while (ifs.getline(Buf, sizeof(Buf))) {
//	//	cout << Buf << endl;
//	//}
//	
//	//3.全局的方法 getline 这个一样不会读取一行中的换行  传入的是一个string类型的字符串 
//	string Buf1;
//	while (getline(ifs, Buf1)) {
//		cout << Buf1 << endl;
//	}
//
//
//	//关闭文件
//	ifs.close();
//}
//class Person {
//
//public:
//	char m_Name[64];
//	int m_Age;
//};
//
//
////二进制文件写入
//void test03() {
//	Person p = { "浩博",109 };
//	//创建文件流对象
//	ofstream ofs;
//	//打开文件
//	ofs.open("test1.txt", ios::out | ios::binary);
//	//写入数据
//	ofs.write((const char*)&p, sizeof(p));
//
//	//关闭文件
//	ofs.close();
//}
////二进制文件读取
//void test04() {
//	Person p1;
//	//创建文件流对象
//	ifstream ifs;
//	//打开文件
//	ifs.open("test1.txt", ios::in | ios::binary);
//	if (!ifs.is_open()) {
//		cout << "file open fail！" << endl;
//		ifs.close();
//		return;
//	}
//	//写入数据
//	ifs.read((char*)&p1, sizeof(p1));
//	//ifs.read((const char*)&a, sizeof(a));
//	cout << "姓名："<<p1.m_Name<<"\n年龄："<<p1.m_Age << endl;
//	//关闭文件
//	ifs.close();
//}
//int main() {
//	//写文件
//	//test01();
//
//	//读文件
//	//test02();
//
//	//二进制写入文件
//	test03();
//
//	//二进制读取文件
//	test04();
//	return 0;
//}